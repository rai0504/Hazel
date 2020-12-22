#pragma once

#include "hazel/Layer.h"

#include "hazel/events/applicationevent.h"
#include "hazel/events/keyevent.h"
#include "hazel/events/mouseevent.h"

namespace Hazel {

	class HAZEL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseButtonMovedEvent(MouseMovedEvent& e);
		bool OnMouseButtonScolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowsResizeEvent(WindowResizeEvent& e);
	private:
		float m_Time = 0.0f;
	};

}