#ifndef PLOT_H
#define PLOT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class plot; }
QT_END_NAMESPACE

class plot : public QMainWindow
{
    Q_OBJECT

public:
    plot(QWidget *parent = nullptr);
    void on_widget_customContextMenuRequested(const QPoint &pos);
    ~plot();

private slots:


    void on_pushButton_clicked();

    void on_debug_button_clicked();

private:
    Ui::plot *ui;
};
#endif // PLOT_H
