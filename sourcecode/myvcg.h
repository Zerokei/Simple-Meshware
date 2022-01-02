#pragma once
#include <vector>
#include <vcg/complex/complex.h>
#include <wrap/io_trimesh/import.h>
#include <wrap/io_trimesh/export.h>

#include <vcg/complex/algorithms/update/topology.h>
#include <vcg/complex/algorithms/update/normal.h>
#include <vcg/complex/algorithms/clean.h>
#include <vcg/complex/algorithms/smooth.h>

#include <vcg/complex/algorithms/update/topology.h>
#include <vcg/complex/algorithms/update/normal.h>
#include <vcg/complex/algorithms/update/flag.h>
#include <vcg/complex/algorithms/refine.h>
#include <vcg/complex/algorithms/refine_loop.h>
#include <vcg/complex/algorithms/bitquad_creation.h>

#include <vcg/complex/algorithms/update/bounding.h>
#include <vcg/complex/algorithms/update/topology.h>
#include <vcg/complex/algorithms/update/normal.h>
#include <vcg/complex/algorithms/update/flag.h>
#include <vcg/complex/algorithms/clustering.h>

#include <windows.h>
#include <GL/GLU.h> //float
#include <GL/GL.h>
#include "QDebug"   //QDebug


//#include <wrap/io_trimesh/import_obj.h>
//#include <wrap/io_trimesh/export_obj.h>
class MyFace;
class MyVertex;

struct MyUsedTypes : public vcg::UsedTypes  <vcg::Use<MyVertex>::AsVertexType, vcg::Use<MyFace>::AsFaceType> {};
class MyVertex : public vcg::Vertex  < MyUsedTypes, vcg::vertex::VFAdj, vcg::vertex::Coord3f, vcg::vertex::TexCoord2f, vcg::vertex::Normal3f, vcg::vertex::Color4b, vcg::vertex::BitFlags  > {};
class MyFace : public vcg::Face  < MyUsedTypes, vcg::face::InfoOcf,  vcg::face::Normal3f, vcg::face::FFAdjOcf, vcg::face::VFAdj, vcg::face::VertexRef, vcg::face::BitFlags > {};
class MyMesh : public vcg::tri::TriMesh<std::vector<MyVertex>, vcg::face::vector_ocf<MyFace> > {
/*//存储点，法向量，纹理坐标
class MyVertex : public vcg::Vertex< MyUsedTypes, vcg::vertex::Coord3f, vcg::vertex::TexCoord2f, vcg::vertex::Normal3f, vcg::vertex::BitFlags  > {};
class MyFace : public vcg::Face<   MyUsedTypes, vcg::face::FFAdj, vcg::face::VFAdj, vcg::face::VertexRef, vcg::face::BitFlags > {};
class MyEdge : public vcg::Edge<   MyUsedTypes> {};
class MyMesh : public vcg::tri::TriMesh<std::vector<MyVertex>, std::vector<MyFace>, std::vector<MyEdge> >{
*/
public:
    float* vertexw;
    float* vertex;
    float* normal;
    unsigned int size;
    MyMesh(const char* filepath) {
        int mask = 0;
        int err = vcg::tri::io::Importer<MyMesh>::Open(*this, filepath, mask);
        if (err == -1) {
            std::cout << "Load Module Error:" << vcg::tri::io::Importer<MyMesh>::ErrorMsg(err) << endl;
            std::cin.get();
        }
        //为每个点计算法线并归一化
        vcg::tri::RequirePerVertexNormal(*this);
        vcg::tri::UpdateNormal<MyMesh>::PerVertexNormalized(*this);
        
        this->face.EnableFFAdjacency();
        vcg::tri::UpdateTopology<MyMesh>::FaceFace(*this);
        vcg::tri::UpdateFlags<MyMesh>::FaceBorderFromFF(*this);


        vcg::tri::UpdateTopology<MyMesh>::VertexFace(*this);

        Extract(false);
        //std::cout << "size =" << v_index << endl;

        //qDebug("Input mesh  vn:%i fn:%i\n", (*this).VN(), (*this).FN());
    }
    void Extract(bool hav) {
        if (hav) {
            delete[] vertex;
            delete[] vertexw;
            delete[] normal;
        }

        vcg::face::vector_ocf<MyFace>& fs = (*this).face;

        size = fs.size();
        vertexw = new float[fs.size() * 3 * 3];
        vertex = new float[fs.size() * 3 * 3];
        normal = new float[fs.size() * 3 * 3];

        int v_index = 0;
        for (auto fi = (*this).face.begin(); fi != (*this).face.end(); ++fi) {
            for (int j = 0; j < 3; ++j) {
                MyVertex* v = fi->V(j);
                if (fi == (*this).face.begin())
                    qDebug() << v->T().u();
                normal[v_index] = v->N().X();
                vertex[v_index++] = v->P().X();
                normal[v_index] = v->N().Y();
                vertex[v_index++] = v->P().Y();
                normal[v_index] = v->N().Z();
                vertex[v_index++] = v->P().Z();
            }
        }
    }
    void Save(const char* filepath) {
        vcg::face::vector_ocf<MyFace>& fs = (*this).face;

        int v_index = 0;
        for (auto fi = (*this).face.begin(); fi != (*this).face.end(); ++fi) {
            for (int j = 0; j < 3; ++j) {
                MyVertex* v = fi->V(j);
                if (fi == (*this).face.begin())
                    qDebug() << v->T().u();
                v->N().X() = normal[v_index];
                v->P().X() = vertexw[v_index++];
                v->N().Y() = normal[v_index];
                v->P().Y() = vertexw[v_index++];
                v->N().Z() = normal[v_index];
                v->P().Z() = vertexw[v_index++];
            }
        }


        int mask = 0;
        int err = vcg::tri::io::Exporter<MyMesh>::Save(*this, filepath);
        if (err == -1) {
            std::cout << "Load Module Error:" << vcg::tri::io::ExporterOBJ<MyMesh>::ErrorMsg(err) << endl;
            std::cin.get();
        }

    }

    void Smooth() {
        vcg::tri::UpdateTopology<MyMesh>::VertexFace(*this);
        vcg::tri::UpdateNormal<MyMesh>::PerFaceNormalized(*this);
        vcg::tri::Smooth<MyMesh>::VertexCoordPasoDoble(*this, 2);
        Extract(true);
    }
    void Simplify() {
        
        vcg::tri::UpdateBounding<MyMesh>::Box(*this);
        vcg::tri::UpdateNormal<MyMesh>::PerFace(*this);
        vcg::tri::Clustering<MyMesh, vcg::tri::AverageColorCell<MyMesh> > Grid;
        unsigned int CellNum = size * 2;
        float CellSize = 0;
        bool DupFace = false;
        Grid.DuplicateFaceParam = DupFace;
        Grid.Init(this->bbox, CellNum, CellSize);
        Grid.AddMesh(*this);
        Grid.ExtractMesh(*this);
        
//        vcg::tri::Clean<MyMesh>::RemoveDuplicateVertex(*this);
//        vcg::tri::Clean<MyMesh>::RemoveUnreferencedVertex(*this);
//        vcg::tri::Allocator<MyMesh>::CompactFaceVector(*this);
//        vcg::tri::Allocator<MyMesh>::CompactVertexVector(*this);
        Extract(true);
    }
    void Refine() {
//        vcg::tri::Clean<MyMesh>::RemoveNonManifoldFace(*this);
//        int i = vcg::tri::Clean<MyMesh>::CountNonManifoldEdgeFF(*this);

        this->face.EnableFFAdjacency();
        vcg::tri::UpdateTopology<MyMesh>::FaceFace(*this);
        vcg::tri::UpdateFlags<MyMesh>::FaceBorderFromFF(*this);
        vcg::tri::UpdateNormal<MyMesh>::PerFaceNormalized(*this);
        vcg::tri::Refine<MyMesh, vcg::tri::MidPoint<MyMesh> >(*this, vcg::tri::MidPoint<MyMesh>(this), 0.0);
        Extract(true);
    }
};