#include "qchecker.h"

QRectF QChecker::boundingRect() const
{
    return QRectF(checker->GetPosition().x() - Checker::radius,
                  checker->GetPosition().y() - Checker::radius,
                  2*Checker::radius, 2*Checker::radius);
}

void QChecker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

QChecker::QChecker(Checker *checker, CheckerViewStyle *style, BattleSide side) : QGraphicsItem()
{
    this->checker = checker;
    this->style = style;
    this->side = side;
}

Checker *QChecker::GetChecker() const
{
    return checker;
}

CheckerViewStyle *QChecker::GetViewStyle() const
{
    return style;
}

BattleSide QChecker::GetBatleSide() const
{
    return side;
}

void QChecker::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
    {
        mousePos = event->QGraphicsSceneMouseEvent::scenePos();
        emit Pressed(this, mousePos);
    }
}

void QChecker::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
    {
        QPointF endPos = event->QGraphicsSceneMouseEvent::scenePos();
        QVector2D diff = QVector2D(endPos - mousePos);
        emit Released(this, diff);
    }
}
