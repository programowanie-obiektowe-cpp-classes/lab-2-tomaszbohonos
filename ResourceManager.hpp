#pragma once

#include "Resource.hpp"

class ResourceManager
{
    Resource* zasob;

public:
    ResourceManager() : zasob(new Resource()) {}

    ~ResourceManager()
    {
        delete zasob;
        zasob = nullptr;
    }

    ResourceManager(const ResourceManager& inny) : zasob(new Resource(*inny.zasob)) {}

    ResourceManager& operator=(const ResourceManager& inny)
    {
        if (this != &inny) {
            *zasob = *inny.zasob;
        }
        return *this;
    }

    ResourceManager(ResourceManager&& inny) noexcept : zasob(inny.zasob) { inny.zasob = nullptr; }

    ResourceManager& operator=(ResourceManager&& inny) noexcept
    {
        if (this != &inny) {
            delete zasob;
            zasob      = inny.zasob;
            inny.zasob = nullptr;
        }
        return *this;
    }

    double get() const
    { 
        return zasob->get();
    }
};
