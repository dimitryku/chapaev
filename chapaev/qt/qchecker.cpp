#include "qchecker.h"

QRectF QChecker::boundingRect() const
{
    return QRectF(checker->getPosition().x() - Checker::radius,
                  checker->getPosition().y() - Checker::radius,
                  2 * Checker::radius, 2 * Checker::radius);
}

void QChecker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(style->getBrush());
    painter->drawEllipse(this->boundingRect());

    painter->drawEllipse(QRectF(checker->getPosition().x() - 2 * Checker::radius / 3,
                                    checker->getPosition().y() - 2 * Checker::radius / 3,
                                    4 * Checker::radius / 3, 4 * Checker::radius / 3));

    painter->drawEllipse(QRectF(checker->getPosition().x() - Checker::radius/4,
                                    checker->getPosition().y() - Checker::radius/4,
                                    Checker::radius/2, Checker::radius/2));
}

QChecker::QChecker(Checker *checker, CheckerViewStyle *style, BattleSide side)
    : QGraphicsItem()
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
    if(event->button() != Qt::MouseButton::LeftButton)
        return;

    mousePos = event->QGraphicsSceneMouseEvent::scenePos();
    emit Pressed(this, mousePos);
}

void QChecker::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() != Qt::MouseButton::LeftButton)
        return;

    QPointF endPos = event->QGraphicsSceneMouseEvent::scenePos();
    QVector2D diff = QVector2D(endPos - mousePos);
    emit Released(this, diff);
}
