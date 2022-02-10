#include <imgui.h>
#include "../event/EventList.h"
#include "UIHelper.h"
#include "../context/context.h"

using namespace ui;

UIHelper::UIHelper()
{
    helper = new filagui::ImGuiHelper(app->getEngine(), app->getView(), fontPath);

    auto viewport = app->getViewport();
    helper->setDisplaySize(viewport->width, viewport->height);

    ImGuiIO &io = ImGui::GetIO();
    io.KeyMap[ImGuiKey_Tab] = SDL_SCANCODE_TAB;
    io.KeyMap[ImGuiKey_LeftArrow] = SDL_SCANCODE_LEFT;
    io.KeyMap[ImGuiKey_RightArrow] = SDL_SCANCODE_RIGHT;
    io.KeyMap[ImGuiKey_UpArrow] = SDL_SCANCODE_UP;
    io.KeyMap[ImGuiKey_DownArrow] = SDL_SCANCODE_DOWN;
    io.KeyMap[ImGuiKey_PageUp] = SDL_SCANCODE_PAGEUP;
    io.KeyMap[ImGuiKey_PageDown] = SDL_SCANCODE_PAGEDOWN;
    io.KeyMap[ImGuiKey_Home] = SDL_SCANCODE_HOME;
    io.KeyMap[ImGuiKey_End] = SDL_SCANCODE_END;
    io.KeyMap[ImGuiKey_Insert] = SDL_SCANCODE_INSERT;
    io.KeyMap[ImGuiKey_Delete] = SDL_SCANCODE_DELETE;
    io.KeyMap[ImGuiKey_Backspace] = SDL_SCANCODE_BACKSPACE;
    io.KeyMap[ImGuiKey_Space] = SDL_SCANCODE_SPACE;
    io.KeyMap[ImGuiKey_Enter] = SDL_SCANCODE_RETURN;
    io.KeyMap[ImGuiKey_Escape] = SDL_SCANCODE_ESCAPE;
    io.KeyMap[ImGuiKey_A] = SDL_SCANCODE_A;
    io.KeyMap[ImGuiKey_C] = SDL_SCANCODE_C;
    io.KeyMap[ImGuiKey_V] = SDL_SCANCODE_V;
    io.KeyMap[ImGuiKey_X] = SDL_SCANCODE_X;
    io.KeyMap[ImGuiKey_Y] = SDL_SCANCODE_Y;
    io.KeyMap[ImGuiKey_Z] = SDL_SCANCODE_Z;
    io.SetClipboardTextFn = [](void *, const char *text)
    {
        SDL_SetClipboardText(text);
    };
    io.GetClipboardTextFn = [](void *) -> const char *
    {
        return SDL_GetClipboardText();
    };
    io.ClipboardUserData = nullptr;

    app->addEventListener(event::SDL_EVENT, id, [&](void *params)
                          { handleSDLEvent(reinterpret_cast<SDL_Event *>(params)); });

    app->addEventListener(event::BEFORE_RENDER, id, std::bind(&UIHelper::handleRender, this, std::placeholders::_1));
}

UIHelper::~UIHelper()
{
    delete helper;
}

filament::View *UIHelper::getView() const noexcept
{
    return helper->getView();
}

filagui::ImGuiHelper *UIHelper::getImGuiHelper()
{
    return helper;
}

void UIHelper::handleSDLEvent(SDL_Event *event) const noexcept
{
    ImGuiIO &io = ImGui::GetIO();

    bool mousePressed[3] = {false};

    switch (event->type)
    {
    case SDL_MOUSEWHEEL:
    {
        if (event->wheel.x > 0)
            io.MouseWheelH += 1;
        if (event->wheel.x < 0)
            io.MouseWheelH -= 1;
        if (event->wheel.y > 0)
            io.MouseWheel += 1;
        if (event->wheel.y < 0)
            io.MouseWheel -= 1;
        break;
    }
    case SDL_MOUSEBUTTONDOWN:
    {
        if (event->button.button == SDL_BUTTON_LEFT)
            mousePressed[0] = true;
        if (event->button.button == SDL_BUTTON_RIGHT)
            mousePressed[1] = true;
        if (event->button.button == SDL_BUTTON_MIDDLE)
            mousePressed[2] = true;
        break;
    }
    case SDL_TEXTINPUT:
    {
        io.AddInputCharactersUTF8(event->text.text);
        break;
    }
    case SDL_KEYDOWN:
    case SDL_KEYUP:
    {
        int key = event->key.keysym.scancode;
        IM_ASSERT(key >= 0 && key < IM_ARRAYSIZE(io.KeysDown));
        io.KeysDown[key] = (event->type == SDL_KEYDOWN);
        io.KeyShift = ((SDL_GetModState() & KMOD_SHIFT) != 0);
        io.KeyAlt = ((SDL_GetModState() & KMOD_ALT) != 0);
        io.KeyCtrl = ((SDL_GetModState() & KMOD_CTRL) != 0);
        io.KeySuper = ((SDL_GetModState() & KMOD_GUI) != 0);
        break;
    }
    }
}

void UIHelper::handleRender(void *data)
{
    static uint64_t frequency = SDL_GetPerformanceFrequency();
    uint64_t now = SDL_GetPerformanceCounter();
    const float timeStep = mTime > 0 ? (float)((double)(now - mTime) / frequency) : (float)(1.0f / 60.0f);
    mTime = now;

    helper->render(timeStep, [&](filament::Engine *engine, filament::View *view)
                   { this->handleImguiCommands(engine, view); });
}

void UIHelper::handleImguiCommands(filament::Engine *engine, filament::View *view)
{
    ImGui::Begin("Hello", nullptr, ImGuiWindowFlags_MenuBar);

    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File", true))
        {
            ImGui::MenuItem("New", nullptr, false, true);
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }

    ImGui::End();
}

void UIHelper::handleAfterRender(void *data)
{
}