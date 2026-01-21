
#ifndef __HAL_GPIO_H__
#define __HAL_GPIO_H__


class HalGpio
{
public:
    struct Spec { void* dt; };

    HalGpio(Spec& spec);

    bool isReady();
    int pinConfigure(bool mode);
    int pinSet(bool set);
    int toggle();
    int read() const;

private:
    Spec& _spec;
};


#endif
