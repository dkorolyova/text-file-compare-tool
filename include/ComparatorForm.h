
#ifndef _COMPAREFILES_H
#define _COMPAREFILES_H

#include <QTextCharFormat>
#include <QScrollBar>
#include <fstream>
#include <functional>
#include <map>
#include <QTextEdit>
#include <QTextDocument>
#include <QTextBlock>
#include <QTextCursor>
#include <memory>
#include "ui_ComparatorForm.h"
#include "ComparedResults.h"
#include "include/FileData.h"

using namespace std::placeholders; 

const std::string kWhiteTheme = "#ffffff";
const std::string kDarkTheme = "#1a2733";
const std::string kBlueTheme = "#a0ddf7";
const std::string kGreenTheme = "#3eb78f";
const std::string kConfigFile = "config.conf";
const int kBorderColor = 300;
const QColor kWhiteForeground = QColor(255, 255, 255);
const auto kColorAdded = Qt::yellow;
const auto kColorDeleted = Qt::red;

class ComparatorForm : public QDialog {
    Q_OBJECT
public:
    ComparatorForm();
    void ShowCompared(std::unique_ptr<ComparedResults>, FileData*);
    void ChangeThemeColor(std::string);
    void SaveCurrentTheme(const std::string);
    void ApplyThemeFromConfig();
    void ApplyHighlight(std::vector<std::pair<int, int> >, QTextDocument*, QColor);
    void ApplyHighlight(std::vector<std::pair<int, int> >, QTextDocument*, std::string);
    template<typename T> void ApplyHighlightAdded(T);
    template<typename T> void ApplyHighlightDeleted(T);
    void InitSettings();
    virtual ~ComparatorForm();
private:
    Ui::ComparatorForm widget;
    std::string color_;
    std::string color_changes_;
    std::vector<std::pair<int, int> > highlight_added;
    std::vector<std::pair<int, int> > highlight_deleted;
    QStringList color_added = {"Yellow", "Pale blue", "Pastel pink", "Mustard"};
    QStringList color_deleted = {"Red", "Slate gray", "Dark blue", "Purple"};
    std::map <std::string, QColor> colors;
    void PopulateColors();
    QColor GetColor(std::string);
};

#endif /* _COMPAREFILES_H */
