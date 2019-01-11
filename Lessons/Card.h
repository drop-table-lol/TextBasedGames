#include <string>
using std::string;

class Card {

private:
  string word;
  string definition;
  string hint;
  string example;

public:
  Card(string w, string d, string h, string e){
    word = w;
    definition = d;
    hint = h;
    example = e;
  }

  void setWord(string w) {
    word = w;
  }
  void setDefinition(string d) {
    definition = d;
  }
  void setHint(string h) {
    hint = h;
  }
  void setExample(string e) {
    example = e;
  }

  string getWord() {
    return word;
  }
  string getDefinition() {
    return definition;
  }
  string getHint() {
    return hint;
  }
  string getExample() {
    return example;
  }

};
