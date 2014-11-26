#pragma once

#include <QWidget>
class QVBoxLayout;
class QLineEdit;
class QLabel;
class QTextEdit;
class QPushButton;
class InspectorSectionWidget;
class QScrollArea;

/*!
 * \brief The InspectorWidgetInterface class
 * Set the global structuration for an inspected element. Inherited by class that implement specific type
 *
 * Setup standard fields : name, color and comments. Manage additional sections added by user.
 */

class InspectorWidgetInterface : public QWidget
{
    Q_OBJECT
public:
    /*!
     * \brief InspectorWidgetInterface Constructor
     * \param inspectedObj The selected object
     * \param parent The parent Widget
     */
    explicit InspectorWidgetInterface(QObject *inspectedObj = 0, QWidget *parent = 0);

signals:

public slots:

    // Manage Sections

    /*!
     * \brief addNewSection Add an InspectorSectionWidget in the main widget
     * \param sectionName The name of this new section.
     * \param content The Widget.
     */
    void addNewSection(QString sectionName, QWidget* content = 0);

    /*!
     * \brief addSubSection Add an InspectorSectionWidget in the choose InspectorSectionWidget
     *
     * \param parentSection The name of the parent InspectorSectionWidget
     * \param subSection The name of the new InspectorSectionWidget
     * \param content The InspectorSectionWidget
     */
    void addSubSection(QString parentSection, QString subSection, InspectorSectionWidget *content);

    /*!
     * \brief addInSection Add any Widget in the choosen InspectorSectionWidget
     *
     * \param sectionName The name of the InspectorSectionWidget
     * \param content The widget
     */
    void addInSection(QString sectionName, QWidget* content); //todo

    /*!
     * \brief insertSection Insert a InspectorSectionWidget in the main widget
     *
     * \param index Index
     * \param name The name of the new Widget
     * \param content The widget
     */
    void insertSection(int index, QString name, QWidget* content = 0);

    void removeSection(QString sectionName); //todo
    void moveSection(int oldIndex, int newIndex, QString sectionName = ""); //todo
    void moveSections(); //todo

    // Manage Values

    void changeColor(); //todo
    void setName(QString newName);
    void setComments(QString newComments);
    void setColor(QColor newColor);
    void changeLabelType(QString type);

    void setInspectedObject(QObject *object);

private:
    QVBoxLayout *_layout;
    QLabel *_objectType;
    QLineEdit *_objectName;
    QPushButton *_colorButton;
    QPixmap *_colorButtonPixmap;
    QScrollArea *_scrollArea;
    QTextEdit *_comments;

    QColor _currentColor = Qt::gray;

    QObject *_inspectedObject;
};
