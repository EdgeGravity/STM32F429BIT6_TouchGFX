#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include "EG_Include.h"

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void EG_ChangeScreen(uint8_t key) {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
