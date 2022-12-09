#ifndef FIELDMETHODDIALOG_H
#define FIELDMETHODDIALOG_H

#include <QDialog>

namespace Ui {
class fieldMethodDialog;
}

struct fieldMethodDialogStatus
{
    enum
    {
        Save = 1,
        Delete = 2
    };
};

class fieldMethodDialog : public QDialog
{
    Q_OBJECT

public:
    fieldMethodDialog(QWidget *parent = nullptr);
    fieldMethodDialog(QString methodText, QWidget *parent = nullptr);
    QString getText();
    ~fieldMethodDialog();

protected slots:
    void saveButton();
    void deleteButton();

private:
    Ui::fieldMethodDialog *ui;
};

#endif // FIELDMETHODDIALOG_H
