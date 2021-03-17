//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as 
// this commented part is listed
//
// Last modified by: Moawya & Ahmad, on 24.02.2021
//


#include "RenderWidget.h"
#include <QPainter>
#include <cmath>
#include <iostream>
using namespace std;

RenderWidget::RenderWidget(QWidget *parent) : QWidget(parent)
{
  // to be implemeted later
}

QSize RenderWidget::minimumSizeHint() const
{
  return QSize(100, 100);
}

QSize RenderWidget::sizeHint() const
{
  return QSize(600, 600);
}

void RenderWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);

 //    painter.setRenderHint(QPainter::Antialiasing, false);
  QColor color(0, 0, 0);
  painter.setPen(color);

  painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
  
  /*for (int X = 100; X < 300; ++X)
  {
    painter.drawPoint(X, X);
  }
  */
  

  //painter.drawLine(250, 50, 150, 150);

  bhm_line(250, 50,150, 150);
  bhm_line(190, 190, 290, 90);

  drawline(250, 50, 290, 90);
	bhm_line(260, 60, 300, 20);
	bhm_line(280, 80, 320, 40);
	bhm_line(300, 20, 320, 40);

  drawline(150, 150, 190, 190);
   bhm_line(160, 160, 120, 200);
   bhm_line(180, 180, 140,220);
   bhm_line(120, 200, 140, 220);


	

	Coordinates(250,133, 0, 360, 15);
	Coordinates(250, 133, 0, 360, 25);
	Coordinates(240, 220, -70,143, 100);
	Coordinates(240, 220, -70, 120, 70);

	bhm_line(130, 260, 230, 260);
	bhm_line(130, 280, 230, 280);
	bhm_line(130, 260, 130, 280);
	bhm_line(230, 260, 230, 280);



	Coordinates(250, 360, 180, 360, 70);

	bhm_line(150, 360, 350, 360);
	bhm_line(150, 380, 350, 380);
	bhm_line(150, 360, 150, 380);
	bhm_line(350, 360, 350, 380);

	


}


void RenderWidget::Coordinates(int xc, int yc, double z1, double z2, double r) {
	QPainter painter(this);
	QColor color(0, 0, 0);
	painter.setPen(color);

	double x, y;
	
	
	while (z1 <z2)
	{

		x = xc + r * cos((z1*3.14)/180);
		y = yc + r * sin((z1 * 3.14) / 180);
		painter.drawPoint(x, y);
		z1 = z1 + 1 / r;
		cout << x << y;
	}

	
}

void RenderWidget::drawline(int x0, int y0, int x1, int y1)
{
	QPainter painter(this);
	QColor color(0, 0, 0);
	painter.setPen(color);

	int dx, dy, p, x, y;

	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y0;

	p = 2 * dy - dx;

	while (x < x1)
	{
		if (p >= 0)
		{


			y = y + 1;
			painter.drawPoint(x, y);
			p = p + (2 * dy) - (2 * dx);
		}
		else
		{
			painter.drawPoint(x, y);
			p = p + (2 * dy);
		}
		x = x + 1;
	}
}



/*
void RenderWidget::myDrawLine(float x1, float y1, float x2, float y2)
{
  QPainter painter(this);
  QColor color(255, 0, 0);
  painter.setPen(color);

  float m = (y2 - y1) / (x2 - x1);
  //  SetPixel(x1, y1, color);   // first point
  painter.drawPoint(x1, y1);

  if (m < 1)
  {
    float y = y1;
    for (int i = x1 + 1; i < x2; ++i)
    {
      y = y + m;
      //      SetPixel(i, round(y), color);
      painter.drawPoint(i, round(y));
    }
  }
  else     // i.e., m > 1
  {
    float mm = 1 / m;
    float x = x1;
    for (int i = y1 + 1; i < y2; ++i)
    {
      x = x + mm;
      //      SetPixel(round(x), i, color);
      painter.drawPoint(round(x), i);
    }
  }

  //  SetPixel(x2, y2, color);   // last point
  painter.drawPoint(x2, y2);
}*/


void RenderWidget::bhm_line(int x1, int y1, int x2, int y2)
{
	QPainter painter(this);
	QColor color(0, 0, 0);
	painter.setPen(color);

	int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
	dx = x2 - x1;
	dy = y2 - y1;
	dx1 = fabs(dx);
	dy1 = fabs(dy);
	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;
	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1;
			y = y1;
			xe = x2;
		}
		else
		{
			x = x2;
			y = y2;
			xe = x1;
		}
		painter.drawPoint(x, y);
		for (i = 0; x < xe; i++)
		{
			x = x + 1;
			if (px < 0)
			{
				px = px + 2 * dy1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					y = y + 1;
				}
				else
				{
					y = y - 1;
				}
				px = px + 2 * (dy1 - dx1);
			}
			painter.drawPoint(x, y);
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1;
			y = y1;
			ye = y2;
		}
		else
		{
			x = x2;
			y = y2;
			ye = y1;
		}
		painter.drawPoint(x, y);
		for (i = 0; y < ye; i++)
		{
			y = y + 1;
			if (py <= 0)
			{
				py = py + 2 * dx1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					x = x + 1;
				}
				else
				{
					x = x - 1;
				}
				py = py + 2 * (dx1 - dy1);
			}
			painter.drawPoint(x, y);
		}
	}
}