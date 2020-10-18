#ifndef VIGENERECIPHERMAINWINDOW_H
#define VIGENERECIPHERMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class VigenereCipherMainWindow;
}
QT_END_NAMESPACE

/*!
 * \brief Класс главного окна приложения.
 */
class VigenereCipherMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param parent - родительский виджет.
     */
    VigenereCipherMainWindow(QWidget *parent = nullptr);
    /*!
     * \brief Деструктор.
     */
    ~VigenereCipherMainWindow();

private:
    /*!
     * \brief Графический интерфейс.
     */
    Ui::VigenereCipherMainWindow *m_ui;
};
#endif // VIGENERECIPHERMAINWINDOW_H
