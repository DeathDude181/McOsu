//================ Copyright (c) 2016, PG, All rights reserved. =================//
//
// Purpose:		static renderer class, so it can be used outside of OsuSlider
//
// $NoKeywords: $sliderrender
//===============================================================================//

#ifndef OSUSLIDERRENDERER_H
#define OSUSLIDERRENDERER_H

#include "cbase.h"

class Shader;
class VertexBuffer;
class VertexArrayObject;

class Osu;
class OsuVR;

class OsuSliderRenderer
{
public:
	static Shader *BLEND_SHADER;
	static Shader *BLEND_SHADER_VR;

public:
	static VertexBuffer *generateSliderVertexBuffer(Osu *osu, const std::vector<Vector2> &points, float hitcircleDiameter, Vector3 translation = Vector3(0, 0, 0));

	static void draw(Graphics *g, Osu *osu, const std::vector<Vector2> &points, float hitcircleDiameter, float from = 0.0f, float to = 1.0f, Color color = 0xffffffff, float alpha = 1.0f, long sliderTimeForRainbow = 0);
	static void draw(Graphics *g, Osu *osu, VertexBuffer *vb, Vector2 translation, float scale, float hitcircleDiameter, float from = 0.0f, float to = 1.0f, Color color = 0xffffffff, float alpha = 1.0f, long sliderTimeForRainbow = 0);
	static void drawVR(Graphics *g, Osu *osu, OsuVR *vr, Matrix4 &mvp, float approachScale, const std::vector<Vector2> &points, float hitcircleDiameter, float from = 0.0f, float to = 1.0f, Color color = 0xffffffff, float alpha = 1.0f, long sliderTimeForRainbow = 0);
	static void drawVR(Graphics *g, Osu *osu, OsuVR *vr, Matrix4 &mvp, float approachScale, VertexBuffer *vb1, VertexBuffer *vb2, float hitcircleDiameter, float from = 0.0f, float to = 1.0f, Color color = 0xffffffff, float alpha = 1.0f, long sliderTimeForRainbow = 0);
	static void drawMM(Graphics *g, Osu *osu, const std::vector<std::vector<Vector2>> &points, float hitcircleDiameter, float from = 0.0f, float to = 1.0f, Color color = 0xffffffff, float alpha = 1.0f, long sliderTimeForRainbow = 0);

private:
	static void drawFillSliderBodyPeppy(Graphics *g, Osu *osu, const std::vector<Vector2> &points, float radius, int drawFromIndex, int drawUpToIndex);
	static void drawFillSliderBodyPeppyVR(Graphics *g, Osu *osu, OsuVR *vr, Matrix4 &mvp, float approachScale, const std::vector<Vector2> &points, float radius, int drawFromIndex, int drawUpToIndex);
	static void drawFillSliderBodyPeppyVR2(Graphics *g, OsuVR *vr, Matrix4 &mvp, float approachScale, const std::vector<Vector2> &points, float radius, int drawFromIndex, int drawUpToIndex);
	static void drawFillSliderBodyMM(Graphics *g, const std::vector<std::vector<Vector2>> &points, float radius, int drawFromIndex, int drawUpToIndex);

	static void checkUpdateVars(Osu *osu, float hitcircleDiameter);

	static void resetRenderTargetBoundingBox();

	// base mesh
	static float MESH_CENTER_HEIGHT;
	static int UNIT_CIRCLE_SUBDIVIDES;
	static std::vector<float> UNIT_CIRCLE;
	static VertexArrayObject *UNIT_CIRCLE_VAO;
	static VertexArrayObject *UNIT_CIRCLE_VAO_TRIANGLES;
	static float UNIT_CIRCLE_VAO_RADIUS;

	// tiny rendering optimization for RenderTarget
	static float m_fBoundingBoxMinX;
	static float m_fBoundingBoxMaxX;
	static float m_fBoundingBoxMinY;
	static float m_fBoundingBoxMaxY;
};

#endif
