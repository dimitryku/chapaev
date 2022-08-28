#include "ActiveCheckerBounder.h"
#include "qchecker.h"

ActiveCheckerBounder::ActiveCheckerBounder()
    : centerPoint()
    , radius(Checker::radius)
{
}

void ActiveCheckerBounder::AddBoundingCircle(QChecker *checker)
{
    centerPoint = checker->GetChecker()->getPosition().toPointF();
    radius = Checker::radius;
}

void ActiveCheckerBounder::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen roundingPen(Qt::blue);
    roundingPen.setWidthF(2);
    painter->setPen(roundingPen);
    painter->drawEllipse(centerPoint, radius, radius);
}

QRectF ActiveCheckerBounder::boundingRect() const
{
    QPointF diff(radius + 2, radius + 2);
    return QRectF(centerPoint - diff, centerPoint + diff);
}

ActiveCheckerBounder::~ActiveCheckerBounder()
{
}
