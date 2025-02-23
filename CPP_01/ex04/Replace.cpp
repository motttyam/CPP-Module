#include "Replace.hpp"

Replace::Replace
(
    const std::string &fileName, 
    const std::string &from,
	const std::string &to
) : _fileName(fileName), _from(from), _to(to) {}

Replace::~Replace () {}

const std::string &Replace::getFileName() const {
    return (_fileName);
}

const std::string &Replace::getFromString() const {
    return (_from);
}

const std::string &Replace::getToString() const {
    return (_to);
}

const std::string &Replace::getFileContent() const {
    return (_fileContent);
}

bool Replace::readFileContent(){
    //　ファイルを開く
    std::ifstream infile(getFileName().c_str());
    if (!infile){
        std::cerr << "File could not be opened." << std::endl;
        return (false);
    }

    // ファイルから取得した文字列をoss型に逐次格納していく
    std::ostringstream oss;
    std::string line;
    while (std::getline(infile, line)) {
        oss << line << "\n";
    }

    // クラスが保持するstring型に格納する
    this->_fileContent = oss.str();

    //  ファイルを閉じる
    infile.close();
    return (true);
}

void Replace::createReplaceFile(){
    // 出力ファイルを開く、なければ作成する
    std::ofstream outfile((getFileName() + ".replace").c_str());
    if (!outfile){
        std::cerr << "Filce could not be created" << std::endl;
        return ;
    }

    // 出力ファイルに置換済みの文字列を上書きする
    outfile << this->replaceFileContent();

    // 出力ファイルを閉じる
    outfile.close();
}

const std::string Replace::replaceFileContent(){
    // 元ファイルの文字列、from文字列、to文字列を取得する
    std::string replaceFileContent = getFileContent();
    std::string fromString = getFromString();
    std::string toString = getToString();

    // 元ファイルの文字列からfrom文字列を検索し、発見すれば文字列を置換
    std::size_t pos = 0;
    while ((pos = replaceFileContent.find(fromString, pos)) != std::string::npos){
        replaceFileContent.erase(pos, fromString.length());
        replaceFileContent.insert(pos, toString);
        pos += toString.length();
    }

    return (replaceFileContent);
}