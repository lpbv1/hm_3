//
// Created by Stephen Clyde on 2/3/17.
//

#include "EdgeTester.h"

#include <iostream>
#include <cmath>
#include "../Point.h"
#include "../Edge.h"

void EdgeTester::testEdge01()
{
    std::cout << "Execute EdgeTester::testEdge01" << std::endl;

    Point p0(0,0,0);
    Point p1(1,0,0);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2()!= &p1)
    {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (e.getLength()!=1)
    {
        std::cout << "Failure in e.getLenth(), length="
                  << e.getLength() << " (expecting 1)"
                  << std::endl;
        return;
    }

    if (e.getSlopeX()!=INFINITY)
    {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting INFINITY)"
                  << std::endl;
        return;
    }

    if (e.getSlopeY()!=0)
    {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0)"
                  << std::endl;
        return;
    }

    if (e.getSlopeZ()!=0)
    {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 0)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testEdge02()
{
    std::cout << "Execute EdgeTester::testEdge02" << std::endl;

    Point p0(1,0,0);
    Point p1(3,4,5);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2()!= &p1)
    {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (fabs(e.getLength() - 6.708203932) > 0.001)
    {
        std::cout << "Failure in e.getLenth(), length="
                  << e.getLength() << " (expecting 6.708203932)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeX() - 0.312347524) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting 0.312347524)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeY() - 0.742781353) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0.742781353)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeZ() - 1.118033989) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 1.118033989)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testParallelEdges()
{
    std::cout << "Execute EdgeTester::testParallelEdges" << std::endl;
    Point p0(0, 0, 0);
    Point p1(1, 0, 0);
    Point p2(0, 1, 1);
    Point p3(2, 1, 1);
    Edge e0(&p0, &p1);
    Edge e1(&p2, &p3);

    Point p4(0, 0, 0);
    Point p5(0, 1, 0);
    Point p6(1, 0, 1);
    Point p7(1, 2, 1);
    Edge e2(&p4, &p5);
    Edge e3(&p6, &p7);

    Point p8(0, 0, 0);
    Point p9(0, 0, 1);
    Point p10(1, 1, 0);
    Point p11(1, 1, 2);
    Edge e4(&p8, &p9);
    Edge e5(&p10, &p11);

    if (e0.isParallelTo(e1)){
        std::cout << "Fail: e0 not parallel to e1" << std::endl;
    }

    if (e2.isParallelTo(e3)){
        std::cout << "Fail: e3 not parallel to e4" << std::endl;
    }

    if (e4.isParallelTo(e5)){
        std::cout << "Fail: e5 not parallel to e6" << std::endl;
    }


    // TODO: Writing a representative set of test cases for edges that are parallel with other
}

void EdgeTester::testNonParallelEdges()
{
    std::cout << "Execute EdgeTester::testNonParallelEdges" << std::endl;
    Point p0(0, 2, 8);
    Point p1(7, 56, 1);
    Point p2(34, 1, 1);
    Point p3(2, 6, 1);
    Edge e0(&p0, &p1);
    Edge e1(&p2, &p3);

    Point p4(0, 567, 0);
    Point p5(0, 1, 4);
    Point p6(1, 27, 1);
    Point p7(8, 2, 1);
    Edge e2(&p4, &p5);
    Edge e3(&p6, &p7);

    Point p8(0, 123, 0);
    Point p9(120, 0, 1);
    Point p10(1, 1, 10);
    Point p11(1, 431, 2);
    Edge e4(&p8, &p9);
    Edge e5(&p10, &p11);

    if (e0.isParallelTo(e1)){
        std::cout << "Fail: e0 parallel to e1" << std::endl;
    }

    if (e2.isParallelTo(e3)){
        std::cout << "Fail: e3 parallel to e4" << std::endl;
    }

    if (e4.isParallelTo(e5)){
        std::cout << "Fail: e5 parallel to e6" << std::endl;
    }
    // TODO: Writing a representative set of test cases for edges that are not parallel with other
}

void EdgeTester::testNonLengthEdges()
{
    std::cout << "Execute EdgeTester::testNonLengthEdges" << std::endl;
    Point p0(0, 0, 0);
    Point p1(0, 0, 0);
    Point p2(1, 1, 1);
    Point p3(1, 1, 1);
    Point p4(INFINITY, INFINITY, INFINITY);
    Point p5(INFINITY, INFINITY, INFINITY);
    Edge e0(&p0, &p1);
    Edge e1(&p2, &p3);
    Edge e2(&p4, &p5);
    if (e0.isValid()){
        std::cout << "Fail: e0 unexpectedly valid" << std::endl;
    }
    if (e1.isValid()){
        std::cout << "Fail: e1 unexpectedly valid" << std::endl;
    }
    if (e2.isValid()){
        std::cout << "Fail: e2 unexpectedly valid" << std::endl;
    }
    // TODO: Writing a representative set of test cases for edges have a length of zero or approximately zero
}

void EdgeTester::testBadEdges()
{
    std::cout << "Execute EdgeTester::testBadEdges" << std::endl;
    Point p0("m, m, m");
    Point p1("n, n, n");
    Edge e0(&p0, &p1);
    if (e0.isValid()){
        std::cout << "Fail: e0 unexpectedly valid" << std::endl;
    }
    // TODO: Writing a representative set of test cases for edges not formed correctly
}
