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

		inline Window& GetWindow() { return *m_Window; };
		
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWidowClose(WindowClosedEvent& e);
		
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};
	
	// TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}

