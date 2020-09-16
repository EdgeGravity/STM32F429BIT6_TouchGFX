#ifndef SENSORCONTAINER_HPP
#define SENSORCONTAINER_HPP

#include <gui_generated/containers/SensorContainerBase.hpp>

class SensorContainer : public SensorContainerBase
{
public:
    SensorContainer();
    virtual ~SensorContainer() {}

    virtual void initialize();
protected:
};

#endif // SENSORCONTAINER_HPP
