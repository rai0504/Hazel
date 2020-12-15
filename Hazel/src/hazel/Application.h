#pragma once

#include "core.h"
#include "events/event.h"

#include "window.h"
#include "hazel/events/applicationevent.h"

namespace Hazel {

	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWidowClose(WindowClosedEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	
	// TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}

