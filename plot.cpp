#include "plot.h"
#include "ui_plot.h"
#include "fparser.hh"
#include <algorithm>

QVector<double> String_Parser (std::string function , double minx, double maxx,double step);

plot::plot(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::plot)
{
    ui->setupUi(this);


}

plot::~plot()
{
    delete ui;
}



void plot::on_pushButton_clicked()
{
    double x_right = ui->xmax_text->toPlainText().toDouble();
    double x_left = ui->xmin_text->toPlainText().toDouble();
    double step = ui->step->toPlainText().toDouble();
    // generate some data:

    QVector<double> x; // initialize with entries 0..100




    std::string input_equation = ui->equation->toPlainText().toStdString();




   QVector<double> y = String_Parser(input_equation,x_left,x_right,step);
   double y_min = *std::min_element(y.constBegin(), y.constEnd());
   double y_max = *std::max_element(y.constBegin(), y.constEnd());




    for (double i =x_left, j = 0;j<y.size(); i += step)
    {
        x.push_back(i);
        j++;
     }
    double x_min = *std::min_element(x.constBegin(), x.constEnd());
    double x_max = *std::max_element(x.constBegin(), x.constEnd());


    // create graph and assign data to it:
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    // set axes ranges, so we see all data:

    ui->widget->xAxis->setRange(x_min, x_max);
    ui->widget->yAxis->setRange(y_min, y_max);
    ui->widget->replot();


}


QVector<double> String_Parser (std::string function , double minx , double maxx ,double step)
{

        FunctionParser fparser;

        //fparser.AddConstant("pi", 3.1415926535897932);

        while(true)
        {
            int res = fparser.Parse(function, "x");
            if (res < 0) break;
            else qDebug()<<"Error"<<endl;
        }

        QVector<double> result;
        double vals[] = { 0 };
            for(vals[0] = minx; vals[0] <= maxx; vals[0] += step)
               result.push_back(fparser.Eval(vals));

    return result;
}



void plot::on_debug_button_clicked()
{
    QVector<double> x; // initialize with entries 0..100
    double x_right = ui->xmax_text->toPlainText().toDouble();
    double x_left = ui->xmin_text->toPlainText().toDouble();
    double step = ui->step->toPlainText().toDouble();

    std::string input_equation = ui->equation->toPlainText().toStdString();

   QVector<double> y = String_Parser(input_equation,x_left,x_right,step);

   double y_min = *std::min_element(y.constBegin(), y.constEnd());
   double y_max = *std::max_element(y.constBegin(), y.constEnd());

    for (double i =x_left, j = 0;j<y.size(); i += step)
    {
        qDebug()<<"i = "<<i<<endl
               <<"step = " <<step <<endl
               << "step + i = "<<step+i<<endl;

        x.push_back(i);
        j++;
     }
    double x_min = *std::min_element(x.constBegin(), x.constEnd());
    double x_max = *std::max_element(x.constBegin(), x.constEnd());


    // generate some data:

    qDebug()<< x_min<<endl
            << x_max<<endl
            << x.size()<<endl;
//    for(auto &z:x)

//        qDebug()<<z<<endl;



}


