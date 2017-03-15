/**
 * @file
 * @author William Meaton <will.meaton@gmail.com>
 *
 * @section LICENSE
 *
 * The MIT License
 * 
 * Copyright (c) 2017 WillMeaton http://willmeaton.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @section DESCRIPTION
 *
 * This class describes a AXTile, it acts like an AXEntity inside of a AXTiledWorld.
 * Tiles can have TileComponents.
 */
#ifndef Tile_hpp
#define Tile_hpp

#include "AXResourceManager.hpp"
#include "AXTileComponent.hpp"
#include "AXGraphics.hpp"
class AXTexture;
class AXTile{
    AXResourceManager* resourceManager;
    AXTexture* texture;
    AXScene* scene;
    std::vector<AXTileComponent*> components;
public:
    AXTile(int textureID);
    AXTile(AXTexture* texture);
    void draw(float x, float y, int w, int h);
    void update();
    void setScene(AXScene* scene);
    AXScene* getScene();
    void addComponent(AXTileComponent* tileComponent);
};
#endif