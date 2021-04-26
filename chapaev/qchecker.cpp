#include "qchecker.h"
#include <iostream>


QRectF qChecker::boundingRect() const
{
    return QRectF(checker->GetPosition().x() - Checker::radius,
                  checker->GetPosition().y() - Checker::radius,
                  2*Checker::radius, 2*Checker::radius);
}

void qChecker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(style->color);
    painter->drawEllipse(this->boundingRect());

    painter->drawEllipse(QRectF(checker->GetPosition().x() - 2*Checker::radius/3,
                                    checker->GetPosition().y() - 2*Checker::radius/3,
                                    4*Checker::radius/3, 4*Checker::radius/3));

    painter->drawEllipse(QRectF(checker->GetPosition().x() - Checker::radius/4,
                                    checker->GetPosition().y() - Checker::radius/4,
                                    Checker::radius/2, Checker::radius/2));
}

qChecker::qChecker(Checker *checker, CheckerViewStyle *style, BattleSide side) : QGraphicsItem()
{
    this->checker = checker;
    this->style = style;
    this->side = side;
}

Checker *qChecker::GetChecker() const
{
    return checker;
}

CheckerViewStyle *qChecker::GetViewStyle() const
{
    return style;
}

BattleSide qChecker::GetBatleSide() const
{
    return side;
}

void qChecker::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //std::cout << "pressed checker" << std::endl;
    //mousePos = event->buttonDownScenePos(Qt::LeftButton);
    //std::cout << std::endl << mousePos.x() << " " << mousePos.y() << " : ";
}

void qChecker::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //std::cout << "released checker" << std::endl;
    QPointF endPos = event->buttonDownScenePos(Qt::LeftButton);
    std::cout << endPos.x() << " " << endPos.y() << std::endl;
    endPos -= mousePos;
    std::cout << endPos.x() << " " << endPos.y() << std::endl;
    //emit
}
