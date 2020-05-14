#include<string> 
#include<iostream>
#include<stack>
#include<vector>
using namespace std; 

string isBalanced(string s) {
    stack<char> stack; 
    char x;
    int i=0;
    while (s[i]) {
        if ((s[i] == '{') || (s[i] == '[') || (s[i] == '(')) {
            stack.push(s[i]);
        } else if (stack.size()>0) {
            if ((s[i] == '}')) {
                if (stack.top() != '{') {
                    return "NO";
                }
                stack.pop();
            }
            if ((s[i] == ']')) {
                if (stack.top() != '[') {
                    return "NO";
                }
                stack.pop();
            }
            if ((s[i] == ')')) {
                if (stack.top() != '(') {
                    return "NO";
                }
                stack.pop();
            }
        } else {
            return "NO";
        }
        i++;
    }
    if (stack.size()>0) {
        return "NO";
    }
    return "YES";   
}

int main() {
    vector<string> str;

    // 1 str.push_back("[()][{}()][](){}([{}(())([[{}]])][])[]([][])(){}{{}{[](){}}}()[]({})[{}{{}([{}][])}]");
    // 2 str.push_back("[()][{}[{}[{}]]][]{}[]{}[]{{}({}(){({{}{}[([[]][[]])()]})({}{{}})})}");
    // 3str.push_back("(])[{{{][)[)])(]){(}))[{(})][[{)(}){[(]})[[{}(])}({)(}[[()}{}}]{}{}}()}{({}](]{{[}}(([{]");
    // 4str.push_back("){[]()})}}]{}[}}})}{]{](]](()][{))])(}]}))(}[}{{)}{[[}[]");
    // 5str.push_back("}(]}){");
    // 6str.push_back("((]()(]([({]}({[)){}}[}({[{])(]{()[]}}{)}}]]{({)[}{(");
    // 7str.push_back("{}{({{}})}[][{{}}]{}{}(){{}[]}{}([[][{}]]())");
    // 8str.push_back("(){}[()[][]]{}(())()[[([])][()]{}{}(({}[]()))()[()[{()}]][]]");
    // 9str.push_back("()([]({}[]){}){}{()}[]{}[]()(()([[]]()))()()()[]()(){{}}()({[{}][]}[[{{}({({({})})})}]])");
    // 10str.push_back("[]([{][][)(])}()([}[}(})}])}))]](}{}})[]({{}}))[])(}}[[{]{}]()[(][])}({]{}[[))[[}[}{(]})()){{(]]){][");
    // 11str.push_back("{()({}[[{}]]()(){[{{}{[[{}]{}((({[]}{}()[])))]((()()))}(()[[[]]])((()[[](({([])()}))[]]))}]})}");
    // 12str.push_back("()(){{}}[()()]{}{}");
    // 13str.push_back("{}()([[]])({}){({[][[][[()]]{{}[[]()]}]})}[](())((())[{{}}])");
    // 14str.push_back("{}(((){}){[]{{()()}}()})[]{{()}{(){()(){}}}}{()}({()(()({}{}()((()((([])){[][{()}{}]})))))})");
    // 15str.push_back("][[{)())))}[)}}}}[{){}()]([][]){{{{{[)}]]{([{)()][({}[){]({{");
    str.push_back("{{}(");
    // str.push_back("{[{((({}{({({()})()})[]({()[[][][]]}){}}))){}}]}{}{({((){{}[][]{}[][]{}}[{}])(())}[][])}");
    // str.push_back("()[[][()[]][]()](([[[(){()[[]](([]))}]]]))");
    // str.push_back("()[]({}{})(()){{{}}()()}({[]()}())[](){}(({()}[{}[{({{}}){({}){({})((({()})))}}}]]))");
    // str.push_back("}[{){({}({)})]([}{[}}{[(([])[(}){[]])([]]}(]]]]{][");
    // str.push_back("[{]{[{(){[}{}(([(]}])(){[[}(]){(})))}}{{)}}{}][({(}))]}({)");
    // str.push_back(")})[(]{][[())]{[]{{}}[)[)}[]){}](}({](}}}[}{({()]]");
    // str.push_back("[[[({[]}({[][[[[][[{(()[][])}()[][]][]{}]]]]}))][(()){}]]]()[{}([]{}){}{{}}]");
    // str.push_back("({[]({[]})}())[][{}[{{(({{{([{}])}}}))}}]]");
    // str.push_back("([((()))()])[][][]{}()(([]))[]()[]((){}[]){}(){{}[]}[[{[]}]]");
    // str.push_back("[[(((({}{[]{}()}){}{{}}){({[]{[{}]{(){}(((){()}))}()}}[[]]()()[()])[[{}{}]()]}))]]{}[]{}({({{}})})");
    // str.push_back("(]{()}((");
    // str.push_back("[][(())[({{{()[]}}{[[][[][[[]{{{[()]{{{{}{[]}[][]}}}}}}]]]]}})]]");
    // str.push_back("}[})})}[)]{}{)");
    // str.push_back("({(}{})))}(}[)[}{)}}[)[{][{(}{{}]({}{[(})[{[({{[}{(]]})}");
    // str.push_back("]}})[]))]{][])[}(])]({[]}[]([)");
    // str.push_back("[{{}{[{{[}[[}([]");
    // str.push_back("[([]){}][({})({[(([])[][])][[{}{([{{}{(()){{{({}{{}}())}}[]}}()[()[{{{([](()){[[[]]]})}}}]]}])}]]})]");
    // str.push_back("]{}{(}))}](})[{]]()(]([}]([}][}{]{[])}{{{]([][()){{})[{({{{[}{}](]}}");
    // str.push_back("{[{}}){(}[][)(}[}][)({[[{]}[(()[}}){}{)([)]}(()))]{)(}}}][");
    // str.push_back("(]{}{(}}}[)[");
    // str.push_back("[]{}{[[]]}([{}]{}[]){{(())}}");
    // str.push_back("[)([{(][(){)[)}{)]]}}([((][[}}(]{}]]}]][(({{{))[[){}{]][))[]{]][)[{{}{()]){)])))){{{[(]}[}}{}]");
    // str.push_back("{({(){[[[][]{}[[([]{})]{}]][[]()()]]}})}[{}{{}}]");
    // str.push_back(")}][(})){))[{}[}");
    // str.push_back("{[]{({]}[}}[{([([)([){{}{(}}[]}}[[{[}[[()(])[}[]");
    // str.push_back("()()()[]");
    // str.push_back("((){}])][]][}{]{)]]}][{]}[)(])[}[({(");
    // str.push_back(")[((])(]]]]((]){{{{())]}]}(}{([}(({}]])[[{){[}]{{}})[){(");
    // str.push_back("}][[{[((}{[]){}}[[[)({[)}]]}(]]{[)[]}{}(){}}][{()]))})]][(((}}");
    // str.push_back("([]){}{{}{}}()([([{}{[[]()([(([]()))()[[]]])]}])])");
    // str.push_back("[()[[]{{[]}()([])}[]][][]][]()[]{}{}[][]{}{}[()(){}]");
    // str.push_back("{[{){]({(((({](]{([])([{{([])[}(){(]](]{[{[]}}())[){})}))[{})))[");
    // str.push_back("{}[()[]][]{}{}[[{{[[({})]()[[()]]]}}]]");
    // str.push_back("{[{}[][]]}[((()))][]({})[]{}{()}");
    // str.push_back("(){[{({})}]}");
    // str.push_back("([]])][{)]({)[]))}]())[}]))][}{(}}})){]}]{[)}(][})[[");
    // str.push_back("((({{}(([{}(())]))[()]{[[[]()]]}})))");
    // str.push_back("}()))}(}]]{{})}][{](]][{]{[[]]]}]]}([)({([))[[(]}])}[}(([{)[)]]([[](]}]}{]{{})[]){]}{])(");
    // str.push_back("{}{}{}{[[()]][]}");
    // str.push_back(")]}]({{})[[[{]{{{}}][))]{{");
    // str.push_back("))){({}])}])}}]{)()(}(]}([");
    // str.push_back("([[]][])[[]()][]()(([[]]{[()[]{[][{}]}[()]]{}{[]}}{{}()}(()[([][]{})[[{}][]]{}[]])))");
    // str.push_back("(]{[({}[){)))}]{[{}][({[({[]))}[}]}{()(([]{]()}})}[]{[)](((]]])([]}}]){)(([]]}[[}[");
    // str.push_back("([[]])({}(([(){{}[{}]}]){[{}]}))[][{}{}](){}");
    // str.push_back("[][][][][][([])][]{({()}[[()()]{([(){[]{}}{(())}{[](){}()({}())}[({}[[]()])][]])}])}");
    // str.push_back("}[{{(}})}}(((())()({]{([]((][(({)[({[]]}[])}]{][{{}]{)][}(])}}}))}}}");
    // str.push_back("[]({})()[]{}{}[]({}{})[]{([])()[()][{()({})[{}{[[()]{}[]][]}(({{[]{()()()}{}[]()}[]}){{}{}})]}]}");
    // str.push_back("{{(([{)]{}({][{](){({([[[][)}[)})(");
    // str.push_back("[{}]{[()({[{}]})]}");
    // str.push_back("[[{}]]");
    // str.push_back("]{{({[{]}[[)]]}{}))}{){({]]}{]([)({{[]){)]{}){){}()})(]]{{])(])[]}][[()()}");
    // str.push_back("{[([}[[{{(]]][}()())]{){(){)]]){})}]{][][(}[]())[}[)})})[][{[)[})()][]))}[[}");
    // str.push_back("]()])}[}}}{]]{)[}(}]]])])}{(}{([{]({)]}])(})[{}[)]])]}[]{{)){}{()}]}((}}{({])[}])[]}");
    // str.push_back("(]}[{}{{][}))){{{([)([[])([]{[");
    // str.push_back("{(()[]){}}(){[]}({{}(()())})([]){}{}(())()[()]{}()");
    // str.push_back("{{}[{}[{}[]]]}{}({{[]}})[[(){}][]]{}(([]{[][]()()}{{{()()}{[]}({}[]{()})}{()}[[]][()]}))");
    // str.push_back("{[][]}[{}[](){}]{{}{[][{}]}}");
    // str.push_back("()(){}(){((){}[])([[]]())}");
    // str.push_back("{}[[{[((}[(}[[]{{]([(}]][[");
    // str.push_back("{}[([{[{{}()}]{}}([[{}[]]({}{{()}[][][]})])])]");
    // str.push_back("{[](}([)(])[]]})()]){[({]}{{{)({}(][{{[}}(]{");
    // str.push_back("[][]{{}[](())}{}({[()]}())[][[][({}([{}]))]]");
    // str.push_back("((()))[]{[(()({[()({[]}{})]}))]}{[]}{{({}{})[{}{}]{()([()])[{()}()[[]{}()]{}{}[]()]}[[]{[]}([])]}}");
    for (auto s: str) {
        cout << isBalanced(s) << endl;
    }
    return 0;
}