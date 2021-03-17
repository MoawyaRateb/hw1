//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as 
// this commented part is listed
//
// Last modified by: Zein Salah, on 24.04.2018
//


#pragma once

#include <QWidget>

class RenderWidget : public QWidget
{
    Q_OBJECT

  public:
    RenderWidget(QWidget *parent = 0);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

	  void myDrawLine(float x1, float y1, float x2, float y2);
      void drawline(int x0, int y0, int x1, int y1);
      void drawline2(int x0, int y0, int x1, int y1);
      void Coordinates(int xc, int yc, double z1, double z2, double r);
      void bhm_line(int x1, int y1, int x2, int y2);
         void  Coordinates1(double r, double z);

  protected:
    void paintEvent(QPaintEvent *event) override;

};
