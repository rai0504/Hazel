#pragma once

#include "core.h"

#include "window.h"
#include "LayerStack.h"
#include "events/event.h"
#include "hazel/events/applicationevent.h"

namespace Hazel {

	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlayer(Layer* overlay);
	private:
		bool OnWidowClose(WindowClosedEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};
	
	// TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}

