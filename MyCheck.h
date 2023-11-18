#pragma once

#include <clang-tidy/ClangTidyCheck.h>

namespace clang::tidy::MyPlugin {

class MyCheck : public ClangTidyCheck {
public:
  explicit MyCheck(StringRef Name, ClangTidyContext *Context);

  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
};

} // namespace clang::tidy::MyPlugin
