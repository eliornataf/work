#include <iostream> /* cout */
#include "canvas.hpp" /* Canvas Header */
#include "colored_canvas.hpp" /* Colored Canvas Header */
#include "drawShape.hpp" /* Draw Shape */
#include "point.hpp" /* Point Header */
#include "shape.hpp" /* Shape Header */
#include "shapeLine.hpp" /* Shape Line Header */
#include "shapeCircle.hpp" /* Shape Cirble Header */
#include "shapeGroup.hpp" /* Shape Group Header */
#include "shapeRectangle.hpp" /* Shape Rectangle */

void ShapeLineTest(){
    std::cout << "Shape Line Test:" << std::endl;
    ascii::Canvas newCanvas(20, 20);
    ShapeLine newLine(ascii::Point(8, 5), ascii::Point(10, 7), '*');
    newLine.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newCanvas.Clear();

    std::cout << "Shape Line Flip Horizontally Test" << std::endl;
    newLine.FlipUnFlipHorizontally();
    newLine.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newLine.FlipUnFlipHorizontally();
    newCanvas.Clear();

    std::cout << "Shape Line Flip Vertically Test" << std::endl;
    newLine.FlipUnFlipVertically();
    newLine.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newLine.FlipUnFlipVertically();
    newCanvas.Clear();

    std::cout << "Shape Line Change Brush Test" << std::endl;
    newLine.SetShapeBrush('&');
    newLine.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newCanvas.Clear();
}

void ShapeCircleTest() {
    std::cout << "Shape Circle Test:" << std::endl << std::endl;
    ascii::Canvas newCanvas(20, 20);
    ShapeCircle newCircle(ascii::Point(5, 5), 5, '#');
    newCircle.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newCanvas.Clear();

    std::cout << "Shape Circle Filled Test" << std::endl << std::endl;
    newCircle.FilledUnFilled();
    newCircle.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newCircle.FilledUnFilled();
    newCanvas.Clear();
}

void ShapeRectangleTest() {
    std::cout << "Shape Rectangle Test:" << std::endl;
    ascii::Canvas newCanvas(20, 20);
    ShapeRectangle newReactangle(ascii::Point(4, 4), 3, 3, '$');
    newReactangle.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newCanvas.Clear();

    std::cout << "Shape Rectangle Flip Horizontally Test" << std::endl;
    newReactangle.FlipUnFlipHorizontally();
    newReactangle.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newReactangle.FlipUnFlipHorizontally();
    newCanvas.Clear();

    std::cout << "Shape Rectangle Flip Vertically Test" << std::endl;
    newReactangle.FlipUnFlipVertically();
    newReactangle.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newReactangle.FlipUnFlipVertically();
    newCanvas.Clear();

    std::cout << "Shape Rectangle Filled Test" << std::endl << std::endl;
    newReactangle.FilledUnFilled();
    newReactangle.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newReactangle.FilledUnFilled();
    newCanvas.Clear();
}

void ShapeGroupTest() {
    std::cout << "Shape Group Test:" << std::endl;
    ascii::Canvas newCanvas(20, 20);
    ShapeLine *newLine = new ShapeLine(ascii::Point(15, 5), ascii::Point(19, 5), '*');
    ShapeCircle *newCircle = new ShapeCircle(ascii::Point(15, 15), 3, '#');
    ShapeRectangle *newReactangle = new ShapeRectangle(ascii::Point(4, 4), 3, 3, '$');
    ShapeGroup newGroup('^');

    newGroup.AddToGroup(newLine);
    newGroup.AddToGroup(newCircle);
    newGroup.AddToGroup(newReactangle);

    newGroup.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newCanvas.Clear();

    std::cout << "Shape Group Filled Test" << std::endl << std::endl;
    newGroup.FilledUnFilledGroup();
    newGroup.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newGroup.FilledUnFilledGroup();
    newCanvas.Clear();

    std::cout << "Shape Group Flip Horizontally Test" << std::endl;
    newGroup.FlipUnFlipGroupItemHorizontally();
    newGroup.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newGroup.FlipUnFlipGroupItemHorizontally();
    newCanvas.Clear();

    std::cout << "Shape Line Flip Vertically Test" << std::endl;
    newGroup.FlipUnFlipGroupItemVertically();
    newGroup.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newGroup.FlipUnFlipGroupItemVertically();
    newCanvas.Clear();

    std::cout << "Shape Group Change Brush Test" << std::endl;
    newGroup.SetShapeBrush('&');
    newGroup.Draw(newCanvas);
    newCanvas.Print(std::cout);

    newCanvas.Clear();
}

int main() {
    ShapeLineTest();
    ShapeCircleTest();
    ShapeRectangleTest();
    ShapeGroupTest();

    return 0;
}