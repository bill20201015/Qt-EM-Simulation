#ifndef DIALOGSET_H
#define DIALOGSET_H

#include <QDialog>
#include <QtMath>
namespace Ui {
class DialogSet;
}

class DialogSet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSet(QWidget *parent = nullptr);
    ~DialogSet();

    double getPermittivity();
    double getConductivity();
    double getMagneticPermeability();
    double getLightSpeed();
    double getAccuracy();
private:
    Ui::DialogSet *ui;
};

#endif // DIALOGSET_H
