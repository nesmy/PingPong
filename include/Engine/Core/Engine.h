#pragma once

#include <stdio.h> 

// for use by application
#include "Application.h"
#include "Log.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "Texture.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include "OpenGLInput.h"

//---------- ENTRY POINT -------------
#include "Entry.h"
//------------------------------------
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)