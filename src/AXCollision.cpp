//
//  AXCollision.cpp
//  Project2
//
//  Created by William Meaton on 26/01/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "headers/AXCollision.h"

namespace AXMath {
    lineCollide::lineCollide(const AXVector2D &v1, const AXVector2D &v2){
        this->v1 = v1;
        this->v2 = v2;
    }
    
    AXVector2D lineCollisionCheckX(const AXVector2D &originalPosition, const AXVector2D &proposedMovement, const lineCollide &lc){
        if(originalPosition.x < lc.v1.x && proposedMovement.x > lc.v1.x){
            return AXVector2D(lc.v1.x, proposedMovement.y);
        }
        return proposedMovement;
    }
    
    AXVector2D lineCollisionCheckY(const AXVector2D &originalPosition, const AXVector2D &proposedMovement, const lineCollide &lc){
        if(originalPosition.y < lc.v1.y && proposedMovement.y > lc.v1.y){
            return AXVector2D(proposedMovement.x, lc.v1.y);
        }
        return proposedMovement;
    }
    
    bool isInsideQuad(const AXVector2D &point, const AXVector2D &v1, const AXVector2D &v2){
        return AXMath::isInsideQuad(point.x, point.y, v1.x, v1.y, v2.x, v2.y);
    }
    
    bool isInsideQuad(const AXVector2D &point, const AXVector2D &v, float w, float h){
        return AXMath::isInsideQuad(point.x, point.y, v.x, v.y, w, h);
    }
    
    bool isInsideQuad(const AXVector2D &point, const AXRect &r){
        return AXMath::isInsideQuad(point.x, point.y, r.getX(), r.getY(), r.getWidth(), r.getHeight());
    }
    
    bool isInsideQuad(const float &x1, const float &y1, const float &x2, const float &y2, const float &x3, const float &y3){
        return (x1 > x2 && x1 < x3) && (y1 > y2 && y1 < y3);
    }
    
    float areaTriangle(float x1, float y1, float x2, float y2, float x3, float y3){
        return areaTriangle(AXVector2D(x1, y1), AXVector2D(x2, y2), AXVector2D(x3, y3));
    }
    
    float areaTriangle(const AXVector2D &v1, const AXVector2D &v2, const AXVector2D &v3){
        float det = 0.0f;
        det = ((v1.x - v3.x) * (v2.y - v3.y)) - ((v2.x - v3.x) * (v1.y - v3.y));
        return (det / 2.0f);
    }
    
    float areaTriangle(const AXTriangle &t){
        return areaTriangle(t.getV1(), t.getV2(), t.getV3());
    }
    
    bool isInsideTriangle(const AXVector2D &point, const AXVector2D &v1, const AXVector2D &v2, const AXVector2D &v3){
        bool b1, b2, b3;
        b1 = areaTriangle(point, v1, v2) < 0.0f;
        b2 = areaTriangle(point, v2, v3) < 0.0f;
        b3 = areaTriangle(point, v3, v1) < 0.0f;
        return ((b1 == b2) && (b2 == b3));
    }
    
    bool isInsideTriangle(const AXVector2D &point, const AXTriangle &t){
        return isInsideTriangle(point, t.getV1(), t.getV2(), t.getV3());
    }
    
    bool isInsideEllipse(const AXVector2D &point, const AXVector2D &cp, float xR, float yR)
    {
        //(((x-cp.x)^2)/rX^2 + ((y-cp.y)^2)/rY^2) <= 1
        return  ( (pow((point.x-cp.x),2)/pow(xR,2)) + (pow((point.y-cp.y),2)/pow(yR,2)) ) <=1;
    }
    bool isInsideEllipse(const AXVector2D &point, const AXEllipse &e)
    {
        //(((x-cp.x)^2)/rX^2 + ((y-cp.y)^2)/rY^2) <= 1
        return  ( (pow((point.x-e.getPosition().x),2)/pow(e.getSize().x,2)) + (pow((point.y-e.getPosition().y),2)/pow(e.getSize().y,2)) ) <=1;
    }
    
    bool isInsideEllipse(const AXVector2D &point, const AXVector2D &cp, float r)
    {
        return isInsideEllipse(point, cp, r, r);
    }

    
    float vectorDistance(const AXVector2D& v1, const AXVector2D& v2){
        return sqrt((v1.x-v2.x)*(v1.x-v2.x)+(v1.y-v2.y)*(v1.y-v2.y));
    }
    
    float vectorDistance(float x1, float y1, float x2, float y2){
        return vectorDistance(AXVector2D(x1, y1), AXVector2D(x2, y2));
    }
}
