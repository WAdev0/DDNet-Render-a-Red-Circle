#include "circle.h"

#include <engine/graphics.h>
#include <engine/shared/config.h>

#include <game/client/animstate.h>
#include <game/client/render.h>
#include <game/generated/client_data.h>
#include <game/generated/protocol.h>

#include <game/client/gameclient.h>

void CRenderCircle::OnRender()
{
	if(g_Config.m_RenderCircle)
	{
		
		vec2 Position = m_pClient->m_LocalCharacterPos;

		
		vec3 Color;
		if(g_Config.m_CircleRainbow)
		{
			
			float Time = (float)time_get() / time_freq();
			Color = vec3(fmod(Time, 1.0f), 1.0f, 1.0f);
		}
		else
		{
			
			Color = vec3(1.0f, 0.0f, 0.0f);
		}

		
		float Radius = g_Config.m_CircleRadius; 
		float Thickness = g_Config.m_CircleThickness; 

		
		Graphics()->TextureClear();
		Graphics()->LinesBegin();
		Graphics()->SetColor(Color.r, Color.g, Color.b, 1.0f);

		const int NUM_SEGMENTS = g_Config.m_CircleSmoothness;
		for(int i = 0; i < NUM_SEGMENTS; ++i)
		{
			float Angle1 = i * 2.0f * pi / NUM_SEGMENTS;
			float Angle2 = (i + 1) * 2.0f * pi / NUM_SEGMENTS;

			vec2 Point1 = Position + vec2(cos(Angle1), sin(Angle1)) * Radius;
			vec2 Point2 = Position + vec2(cos(Angle2), sin(Angle2)) * Radius;

			
			for(float t = -Thickness / 2; t <= Thickness / 2; t += 1.0f)
			{
				IGraphics::CLineItem Line(Point1.x, Point1.y + t, Point2.x, Point2.y + t);
				Graphics()->LinesDraw(&Line, 1);
			}
		}

		Graphics()->LinesEnd();
	}
}
