#include "hzpch.h"
#include "winwindow.h"
#include "hazel/Log.h"

namespace Hazel {

	static bool s_GLFWInitialised = false;

	Window* Window::Create(const WindowsProps& props)
	{
		return new WinWindow(props);
	}

	WinWindow::WinWindow(const WindowsProps& props)
	{
		Init(props);
	}

	WinWindow::~WinWindow()
	{
		Shutdown();
	}

	void WinWindow::Init(const WindowsProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		HZ_CORE_INFO("Creating window {0} {1} {2}", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialised)
		{
			// TODO: glfwTermiate on system shutdown
			int success = glfwInit();
			HZ_CORE_ASSERT(success, "Could not initialise GLFW!");

			s_GLFWInitialised = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WinWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WinWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WinWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WinWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

}
