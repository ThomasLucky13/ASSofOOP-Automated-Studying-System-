#ifndef LABSMODUL_H
#define LABSMODUL_H

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class LabsModul;
}

class LabsModul : public QWidget
{
    Q_OBJECT

public:
    explicit LabsModul(QWidget *parent = nullptr);
    ~LabsModul();

private:
    Ui::LabsModul *ui;
    QButtonGroup *themsButtons;

protected slots:
    void themeChoosed(int);
};

#endif // LABSMODUL_H
