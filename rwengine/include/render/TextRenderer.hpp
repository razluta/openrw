#pragma once
#include <engine/GameData.hpp>
#include "OpenGLRenderer.hpp"

#define GAME_FONTS 3
#define GAME_GLYPHS 192

class GameRenderer;
/**
 * @brief Handles rendering of bitmap font textures.
 * 
 * In future, strings textures might be cached to improve performance, but
 * for now, we just render each glyph on it's own quad
 */
class TextRenderer
{
public:
	
	/**
	 * @todo Can this be merged with the gamestate text entries?
	 */
	struct TextInfo
	{
		enum TextAlignemnt
		{
			Left = 0,
			Right = 1,
			Center = 2
		};
		
		/// Font index @see TextRenderer::setFontTexture
		int font;
		/// Message to be displayed (including markup)
		std::string text;
		/// Extra text parameter
		std::string varText;
		/// On screen position
		glm::vec2 screenPosition;
		/// font size
		float size;
		/// Base colour
		glm::vec3 baseColour;
		/// Horizontal Alignment
		TextAlignemnt align;
		
		TextInfo();
	};
	
	/**
	 * Stores the information for kerning a glyph
	 */
	struct GlyphInfo
	{
		float widthFrac;
	};
	
	TextRenderer(GameRenderer* renderer);
	~TextRenderer();
	
	void setFontTexture( int index, const std::string& font );
	
	void renderText( const TextInfo& ti );
	
private:
	std::string fonts[GAME_FONTS];
	GlyphInfo glyphData[GAME_GLYPHS];

	GameRenderer* renderer;
	Renderer::ShaderProgram* textShader;
	
	GeometryBuffer gb;
	DrawBuffer db;
};