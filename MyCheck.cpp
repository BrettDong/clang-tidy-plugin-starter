#include "MyCheck.h"

namespace clang::tidy::MyPlugin {

using namespace ast_matchers;

MyCheck::MyCheck(StringRef Name, ClangTidyContext *Context)
    : ClangTidyCheck(Name, Context) {}

void MyCheck::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(
      callExpr(callee(functionDecl(hasName("foo")))).bind("fooCall"), this);
}

void MyCheck::check(const MatchFinder::MatchResult &Result) {
  const auto *fooCall = Result.Nodes.getNodeAs<CallExpr>("fooCall");
  if (!fooCall) {
    return;
  }
  diag(fooCall->getBeginLoc(), "Calling deprecated API foo() is discouraged");
}

} // namespace clang::tidy::MyPlugin
