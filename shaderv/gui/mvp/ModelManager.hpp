#ifndef _MODEL_MANAGER_HPP_
#define _MODEL_MANAGER_HPP_

#include "Model.hpp"

class ModelManager {
public:
    template <typename M, class ...Args>
    bool BuildModel(const Args& ...args)
    {
        static_assert(std::is_base_of<Model, M>(),
            "Template is not base of Model");
        auto it = models.find(typeid(M).name());
        if (it != models.end()) {
            return false;
        }
        auto model = std::make_unique<M>(args...);
        if (!model->Init()) {
            return false;
        }
        models[typeid(M).name()] = std::move(model);
        return true;
    }

    template <typename M>
    M* ObtainModel() const
    {
        static_assert(std::is_base_of<Model, M>(),
            "Template is not base of Model");
        auto it = models.find(typeid(M).name());
        return ((it == models.end()) ? nullptr :
            dynamic_cast<M*>(it->second.get()));
    }

private:
    std::unordered_map<std::string, std::unique_ptr<Model>> models;
};

#endif
