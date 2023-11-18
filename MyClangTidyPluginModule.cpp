#include <clang-tidy/ClangTidyModule.h>
#include <clang-tidy/ClangTidyModuleRegistry.h>

#include "MyCheck.h"

namespace clang::tidy::MyPlugin {

class MyClangTidyPluginModule : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<MyCheck>("my-check");
  }
};

[[maybe_unused]] static ClangTidyModuleRegistry::Add<MyClangTidyPluginModule>
    X("my-module", "Adds checks in my plugin.");

} // namespace clang::tidy::MyPlugin
