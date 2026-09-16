#pragma once
#include <string>
#include <Client.h>
#include <Biscuit.h>
#include "Liste.h"


class Commande {

private:
    Liste client;
    Liste biscuits;
public:
    Commande();
    ~Commande();
};