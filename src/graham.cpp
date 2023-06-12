#include "graham.hpp"

Graham::Graham(PointCollection *pointCollection)
{
  this->pointCollection = pointCollection;
  this->convexHull = new PointCollection();
}

Graham::~Graham()
{
  delete this->convexHull;
}

int Graham::orientation(Point p, Point q, Point r)
{
  int val = (q.y - p.y) * (r.x - q.x) -
            (q.x - p.x) * (r.y - q.y);

  if (val == 0)
  {
    return 0;
  }

  return (val > 0) ? 1 : 2;
}

void Graham::run()
{
  Point *points = this->pointCollection->toArray();
  int size = this->pointCollection->getSize();
  int leftmost = 0;
  int current = 0;
  int next = 0;
  int i = 0;

  for (i = 0; i < size; i++)
  {
    if (points[i].x < points[leftmost].x)
    {
      leftmost = i;
    }
  }

  current = leftmost;

  do
  {
    this->convexHull->add(points[current]);
    next = (current + 1) % size;

    for (i = 0; i < size; i++)
    {
      if (Graham::orientation(points[current], points[i], points[next]) == 2)
      {
        next = i;
      }
    }

    current = next;
  } while (current != leftmost);
}

void Graham::print()
{
  this->convexHull->print();
}
