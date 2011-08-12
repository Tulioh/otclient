#ifndef OTMLPARSER_H
#define OTMLPARSER_H

#include <otml/otmlnode.h>

#include <istream>

class OTMLParser
{
public:
    OTMLParser(std::istream& in, std::string what = "");
    ~OTMLParser();

    OTMLNode* getDocument() const { return m_rootNode; }
    std::string what() { return m_rootNode->what(); }

    void throwError(const std::string& message, int line);

protected:
    void parse();
    void parseLine(std::string line);
    void parseNode(OTMLNode* node, std::string data);
    void parseNodeValue(OTMLNode* node, std::string value);
    void parseTextValue(std::string& value);

    void parseTokens(std::string data, std::vector<std::string>& out);

private:
    int m_currentDepth;
    int m_currentLine;
    OTMLNode* m_rootNode;
    OTMLNode* m_currentParent;
    OTMLNode* m_previousNode;
    std::istream& m_in;
};

#endif // OTMLPARSER_H