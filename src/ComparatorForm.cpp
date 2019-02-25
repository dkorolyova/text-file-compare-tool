
#include "../include/ComparatorForm.h"

ComparatorForm::ComparatorForm() {
    widget.setupUi(this);
    PopulateColors();
    ApplyThemeFromConfig();  
    InitSettings();
    connect(widget.whiteTheme, &QRadioButton::clicked,
        [ = ]() {this->ChangeThemeColor(kWhiteTheme);});
    connect(widget.darkTheme, &QRadioButton::clicked,
        [ = ](){this->ChangeThemeColor(kDarkTheme);});
    connect(widget.blueTheme, &QRadioButton::clicked,
        [ = ](){this->ChangeThemeColor(kBlueTheme);});
    connect(widget.greenTheme, &QRadioButton::clicked,
        [ = ](){this->ChangeThemeColor(kGreenTheme);});  
    connect(widget.firstFileText->verticalScrollBar(), SIGNAL(valueChanged(int)),
            widget.secondFileText->verticalScrollBar(), SLOT(setValue(int)));
    connect(widget.secondFileText->verticalScrollBar(), SIGNAL(valueChanged(int)),
            widget.firstFileText->verticalScrollBar(), SLOT(setValue(int)));
}

void ComparatorForm::ShowCompared(std::unique_ptr<ComparedResults> compared_results, FileData *file_data) {
    widget.firstFileText->setText(file_data->GetText().c_str());
    widget.secondFileText->setText(file_data->GetTextToCompare().c_str());
    widget.pathToFirstFile->setText(file_data->GetPathFirst().c_str());
    widget.pathToSecondFile->setText(file_data->GetPathSecond().c_str());

    this->highlight_added = compared_results->GetHighlightAdded();
    this->highlight_deleted = compared_results->GetHighlightDeleted();

    this->ApplyHighlightAdded<QColor>(kColorAdded);
    this->ApplyHighlightDeleted<QColor>(kColorDeleted);
}

void ComparatorForm::ApplyHighlight(std::vector<std::pair<int, int> > get_highlight, QTextDocument *edit, std::string color) {
    QColor qcolor = this->GetColor(color);
    this->ApplyHighlight(get_highlight, edit, qcolor);
}

void ComparatorForm::ApplyHighlight(std::vector<std::pair<int, int> > get_highlight, QTextDocument *edit, QColor color) {
    for (auto item : get_highlight) {
        QTextCharFormat fmt;
        fmt.setBackground(color);
        if (color.red() + color.green() + color.blue() < kBorderColor) {
            fmt.setForeground(kWhiteForeground);
        }
        QTextCursor cursor(edit);
        cursor.setPosition(item.first - 1, QTextCursor::MoveAnchor);
        cursor.setPosition(item.second - 1, QTextCursor::KeepAnchor);
        cursor.setCharFormat(fmt);
    }
}

template<typename T>
void ComparatorForm::ApplyHighlightAdded(T color) {
    QTextDocument *edit_second = widget.secondFileText->document();
    ApplyHighlight(this->highlight_added, edit_second, color);
}

template<typename T>
void ComparatorForm::ApplyHighlightDeleted(T color) {
    QTextDocument *edit_first = widget.firstFileText->document();
    ApplyHighlight(this->highlight_deleted, edit_first, color);
}

void ComparatorForm::ChangeThemeColor(std::string color) {
    SaveCurrentTheme(color);
    if (color == kDarkTheme) {
        widget.firstFileText->setStyleSheet("color:black; background-color:white;");
        widget.secondFileText->setStyleSheet("color:black; background-color:white;");
        this->setStyleSheet(std::string("color:white; background-color: " + color + ";").c_str());
        return ;
    } 
    widget.firstFileText->setStyleSheet("background-color:white;");
    widget.secondFileText->setStyleSheet("background-color:white;");
    std::string style = std::string("background-color: ") + color + ";";
    this->setStyleSheet(style.c_str());
}

void ComparatorForm::SaveCurrentTheme(const std::string color) {
    std::ofstream currenttheme(kConfigFile);
    currenttheme << color;
    currenttheme.close();
}

void ComparatorForm::ApplyThemeFromConfig() {
    std::ifstream currenttheme(kConfigFile);
    currenttheme >> color_;
    if (!(currenttheme.is_open()) || color_.empty()) {
        ChangeThemeColor(kWhiteTheme);
    } else {
        currenttheme.close();
        ChangeThemeColor(color_);
    }
}

void ComparatorForm::InitSettings() {
    QComboBox* combo_added = widget.colorAddedText;
    QComboBox* combo_deleted = widget.colorDeletedText;
    combo_added->addItems(color_added);
    combo_deleted->addItems(color_deleted);
    connect(combo_added, &QComboBox::currentTextChanged,
            [ = ](){
                std::string color = widget.colorAddedText->itemText(widget.colorAddedText->currentIndex()).toUtf8().constData();
                this->ApplyHighlightAdded<std::string>(color);
            });
    connect(combo_deleted, &QComboBox::currentTextChanged,
            [ = ](){
                std::string color = widget.colorDeletedText->itemText(widget.colorDeletedText->currentIndex()).toUtf8().constData();
                this->ApplyHighlightDeleted<std::string>(color);
            });
}

void ComparatorForm::PopulateColors() {
    this->colors = {
        { "Red", QColor(255, 0, 0)},
        { "Slate gray", QColor(112, 128, 144)},
        { "Dark blue", QColor(24, 70, 145)},
        { "Purple", QColor(128, 0, 128)},
        { "Yellow", QColor(255, 255, 0)},
        { "Pale blue", QColor(175, 238, 238)},
        { "Pastel pink", QColor(255, 209, 220)},
        { "Mustard", QColor(255, 219, 88)}
    };
}

QColor ComparatorForm::GetColor(std::string color) {
    return colors.at(color);
}

ComparatorForm::~ComparatorForm() {
}