#pragma once
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "sem.h"

void* consumer();
void* producer();