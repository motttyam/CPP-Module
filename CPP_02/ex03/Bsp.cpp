#include "Point.hpp"

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point) {

    vector2D ab, bc, ca, pa, pb, pc;
    
    // 三角形各点同士のベクトル
    ab.x = b.getX() - a.getX();
    ab.y = b.getY() - a.getY();
    bc.x = c.getX() - b.getX();
    bc.y = c.getY() - b.getY();
    ca.x = a.getX() - c.getX();
    ca.y = a.getY() - c.getY();
    
    // 与えられたポイントと三角形の各点のベクトル
    pa.x = point.getX() - a.getX();
    pa.y = point.getY() - a.getY();
    pb.x = point.getX() - b.getX();
    pb.y = point.getY() - b.getY();
    pc.x = point.getX() - c.getX();
    pc.y = point.getY() - c.getY();

    // 外積(クロス積)を計算する
    // 3次元空間内の2つのベクトル、a=(ax,ay,az)、b=(bx,by,bz)の外積は
    // a→ ✕ b→ =  (ay・bz　−　az・by(0), az・bx　−　ax・bz(0), ax・by　−　ay・bx)
    Fixed cross_z_pa_ab = pa.x * ab.y - pa.y * ab.x;
    Fixed cross_z_pb_bc = pb.x * bc.y - pb.y * bc.x;
    Fixed cross_z_pc_ca = pc.x * ca.y - pc.y * ca.x;

    // 各外積の符号をチェックする
    bool cross_pa_ab_sign = cross_z_pa_ab > Fixed(0);
    bool cross_pb_bc_sign = cross_z_pb_bc > Fixed(0);
    bool cross_pc_ca_sign = cross_z_pc_ca > Fixed(0);

    // すべての符号が等しければ(== 三角形の内側)trueを返す
    return (cross_pa_ab_sign == cross_pb_bc_sign && cross_pb_bc_sign == cross_pc_ca_sign);
}
