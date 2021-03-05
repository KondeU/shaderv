#ifndef _PRESENTER_MANAGER_HPP_
#define _PRESENTER_MANAGER_HPP_

#include "Presenter.hpp"

class PresenterManager {
public:
    template <typename P, typename V, class ...Args>
    bool BuildPresenter(V& view, const Args& ...args)
    {
        static_assert(std::is_base_of<Presenter, P>(),
            "Template is not base of Presenter");
        static_assert(std::is_base_of<View, V>(),
            "Template is not base of View");
        auto it = presenters.find(typeid(P).name());
        if (it != presenters.end()) {
            return false;
        }
        auto presenter = std::make_unique<P>(view, args...);
        if (!presenter->Init()) {
            return false;
        }
        presenters[typeid(P).name()] = std::move(presenter);
        return true;
    }

private:
    std::unordered_map<std::string, std::unique_ptr<Presenter>> presenters;
};

#endif
