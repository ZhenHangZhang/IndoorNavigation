//
//  OIMGeometry.h
//  OIMMapKit
//
//  Created by AutoNavi.
//  Copyright (c) 2013年 AutoNavi. All rights reserved.
//
#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    typedef struct {
        CLLocationCoordinate2D northEast;
        CLLocationCoordinate2D southWest;
    } OIMCoordinateBounds;
    
    typedef struct {
        CLLocationDegrees latitudeDelta;
        CLLocationDegrees longitudeDelta;
    } OIMCoordinateSpan;
    
    typedef struct {
        CLLocationCoordinate2D center;
        OIMCoordinateSpan span;
    } OIMCoordinateRegion;
    
    static inline OIMCoordinateBounds OIMCoordinateBoundsMake(CLLocationCoordinate2D northEast,CLLocationCoordinate2D southWest)
    {
        return (OIMCoordinateBounds){northEast, southWest};
    }
    
    static inline OIMCoordinateSpan OIMCoordinateSpanMake(CLLocationDegrees latitudeDelta, CLLocationDegrees longitudeDelta)
    {
        return (OIMCoordinateSpan){latitudeDelta, longitudeDelta};
    }
    
    static inline OIMCoordinateRegion OIMCoordinateRegionMake(CLLocationCoordinate2D centerCoordinate, OIMCoordinateSpan span)
    {
        return (OIMCoordinateRegion){centerCoordinate, span};
    }
    
    /*!
     @brief 生成一个新的OIMCoordinateRegion
     @param centerCoordinate 中心点坐标
     @param latitudinalMeters 垂直跨度(单位 米)
     @param longitudinalMeters 水平跨度(单位 米)
     @return 新的OIMCoordinateRegion
     */
    extern OIMCoordinateRegion OIMCoordinateRegionMakeWithDistance(CLLocationCoordinate2D centerCoordinate, CLLocationDistance latitudinalMeters, CLLocationDistance longitudinalMeters);
    
    /** 平面投影坐标结构定义 */
    typedef struct {
        double x;
        double y;
    } OIMMapPoint;
    
    /** 平面投影大小结构定义 */
    typedef struct {
        double width;
        double height;
    } OIMMapSize;
    
    /** 平面投影矩形结构定义 */
    typedef struct {
        OIMMapPoint origin;
        OIMMapSize size;
    } OIMMapRect;
    
    /**
     比例关系:OIMZoomScale = Screen Point / OIMMapPoint, 当OIMZoomScale = 1时, 1 screen point = 1 OIMMapPoint, 当OIMZoomScale = 0.5时, 1 screen point = 2 OIMMapPoints
     */
    typedef double OIMZoomScale;
    
    /*!
     const常量定义
     */
    extern const OIMMapSize OIMMapSizeWorld;
    
    extern const OIMMapRect OIMMapRectWorld;
    
    extern const OIMMapRect OIMMapRectNull;
    
    extern const OIMMapRect OIMMapRectZero;
    
    /*!
     @brief 经纬度坐标转平面投影坐标
     @param coordinate 要转化的经纬度坐标
     @return 平面投影坐标
     */
    extern OIMMapPoint OIMMapPointForCoordinate(CLLocationCoordinate2D coordinate);
    
    /*!
     @brief 平面投影坐标转经纬度坐标
     @param mapPoint 要转化的平面投影坐标
     @return 经纬度坐标
     */
    extern CLLocationCoordinate2D OIMCoordinateForMapPoint(OIMMapPoint mapPoint);
    
    /*!
     @brief 平面投影矩形转region
     @param mapPoint 要转化的平面投影矩形
     @return region
     */
    extern OIMCoordinateRegion OIMCoordinateRegionForMapRect(OIMMapRect rect);
    
    /*!
     @brief region转平面投影矩形
     @param region 要转化的region
     @return 平面投影矩形
     */
    extern OIMMapRect OIMMapRectForCoordinateRegion(OIMCoordinateRegion region);
    
    /*!
     @brief 单位投影的距离
     */
    extern CLLocationDistance OIMMetersPerMapPointAtLatitude(CLLocationDegrees latitude);
    
    /*!
     @brief 1米对应的投影
     */
    extern double OIMMapPointsPerMeterAtLatitude(CLLocationDegrees latitude);
    
    /*!
     @brief 投影两点之间的距离
     */
    extern CLLocationDistance OIMMetersBetweenMapPoints(OIMMapPoint a, OIMMapPoint b);
    
    /*!
     @brief 经纬度间的面积(单位 平方米)
     */
    extern double OIMAreaBetweenCoordinates(CLLocationCoordinate2D northEast, CLLocationCoordinate2D southWest);
    
    /*!
     @brief 获取Inset后的OIMMapRect
     */
    extern OIMMapRect OIMMapRectInset(OIMMapRect rect, double dx, double dy);
    
    /*!
     @brief 合并两个OIMMapRect
     */
    extern OIMMapRect OIMMapRectUnion(OIMMapRect rect1, OIMMapRect rect2);
    
    /*!
     @brief 判断size1是否包含size2
     */
    extern BOOL OIMMapSizeContainsSize(OIMMapSize size1, OIMMapSize size2);
    
    /*!
     @brief 判断点是否在矩形内
     */
    extern BOOL OIMMapRectContainsPoint(OIMMapRect rect, OIMMapPoint point);
    
    /*!
     @brief 判断两矩形是否相交
     */
    extern BOOL OIMMapRectIntersectsRect(OIMMapRect rect1, OIMMapRect rect2);
    
    /*!
     @brief 判断矩形rect1是否包含矩形rect2
     */
    extern BOOL OIMMapRectContainsRect(OIMMapRect rect1, OIMMapRect rect2);
    
    /*!
     @brief 判断点是否在圆内
     */
    extern BOOL OIMCircleContainsPoint(OIMMapPoint point, OIMMapPoint center, double radius);
    
    /*!
     @brief 判断经纬度点是否在圆内
     */
    extern BOOL OIMCircleContainsCoordinate(CLLocationCoordinate2D point, CLLocationCoordinate2D center, double radius);
    
    /*!
     @brief 判断点是否在多边形内
     */
    extern BOOL OIMPolygonContainsPoint(OIMMapPoint point, OIMMapPoint *polygon, NSUInteger count);
    /*!
     @brief 判断经纬度点是否在多边形内
     */
    extern BOOL OIMPolygonContainsCoordinate(CLLocationCoordinate2D point, CLLocationCoordinate2D *polygon, NSUInteger count);
    
    /*!
     获取在lineStart和lineEnd组成的线段上距离point距离最近的点.
     
     @param lineStart 线段起点.
     @param lineEnd   线段终点.
     @param point     测试点.
     @return 距离point最近的点坐标.
     */
    extern OIMMapPoint OIMGetNearestMapPointFromLine(OIMMapPoint lineStart, OIMMapPoint lineEnd, OIMMapPoint point);
    
    /*!
     获取墨卡托投影切块回调block，如果是无效的映射，则返回(-1, -1, 0, 0, 0, 0).
     
     @param offsetX 左上点距离所属tile的位移X, 单位像素.
     @param offsetY 左上点距离所属tile的位移Y, 单位像素.
     @param minX    覆盖tile的最小x.
     @param maxX    覆盖tile的最大x.
     @param minY    覆盖tile的最小y.
     @param maxY    覆盖tile的最大y.
     */
    typedef void (^AMapTileProjectionBlock)(int offsetX, int offsetY, int minX, int maxX, int minY, int maxY);
    
    /*!
     根据所给经纬度区域获取墨卡托投影切块信息.
     
     @param bounds          经纬度区域.
     @param levelOfDetails  对应缩放级别, 取值0-20。
     @param tileProjection  返回的切块信息block.
     */
    extern void OIMGetTileProjectionFromBounds(OIMCoordinateBounds bounds, int levelOfDetails, AMapTileProjectionBlock tileProjection);
    
    
    static inline OIMMapPoint OIMMapPointMake(double x, double y)
    {
        return (OIMMapPoint){x, y};
    }
    
    static inline OIMMapSize OIMMapSizeMake(double width, double height)
    {
        return (OIMMapSize){width, height};
    }
    
    static inline OIMMapRect OIMMapRectMake(double x, double y, double width, double height)
    {
        return (OIMMapRect){OIMMapPointMake(x, y), OIMMapSizeMake(width, height)};
    }
    
    static inline double OIMMapRectGetMinX(OIMMapRect rect)
    {
        return rect.origin.x;
    }
    
    static inline double OIMMapRectGetMinY(OIMMapRect rect)
    {
        return rect.origin.y;
    }
    
    static inline double OIMMapRectGetMidX(OIMMapRect rect)
    {
        return rect.origin.x + rect.size.width / 2.0;
    }
    
    static inline double OIMMapRectGetMidY(OIMMapRect rect)
    {
        return rect.origin.y + rect.size.height / 2.0;
    }
    
    static inline double OIMMapRectGetMaxX(OIMMapRect rect)
    {
        return rect.origin.x + rect.size.width;
    }
    
    static inline double OIMMapRectGetMaxY(OIMMapRect rect)
    {
        return rect.origin.y + rect.size.height;
    }
    
    static inline double OIMMapRectGetWidth(OIMMapRect rect)
    {
        return rect.size.width;
    }
    
    static inline double OIMMapRectGetHeight(OIMMapRect rect)
    {
        return rect.size.height;
    }
    
    static inline BOOL OIMMapPointEqualToPoint(OIMMapPoint point1, OIMMapPoint point2) {
        return point1.x == point2.x && point1.y == point2.y;
    }
    
    static inline BOOL OIMMapSizeEqualToSize(OIMMapSize size1, OIMMapSize size2) {
        return size1.width == size2.width && size1.height == size2.height;
    }
    
    static inline BOOL OIMMapRectEqualToRect(OIMMapRect rect1, OIMMapRect rect2) {
        return
        OIMMapPointEqualToPoint(rect1.origin, rect2.origin) &&
        OIMMapSizeEqualToSize(rect1.size, rect2.size);
    }
    
    static inline BOOL OIMMapRectIsNull(OIMMapRect rect) {
        return isinf(rect.origin.x) || isinf(rect.origin.y);
    }
    
    static inline BOOL OIMMapRectIsEmpty(OIMMapRect rect) {
        return OIMMapRectIsNull(rect) || (rect.size.width == 0.0 && rect.size.height == 0.0);
    }
    
    static inline NSString *OIMStringFromMapPoint(OIMMapPoint point) {
        return [NSString stringWithFormat:@"{%.1f, %.1f}", point.x, point.y];
    }
    
    static inline NSString *OIMStringFromMapSize(OIMMapSize size) {
        return [NSString stringWithFormat:@"{%.1f, %.1f}", size.width, size.height];
    }
    
    static inline NSString *OIMStringFromMapRect(OIMMapRect rect) {
        return [NSString stringWithFormat:@"{%@, %@}", OIMStringFromMapPoint(rect.origin), OIMStringFromMapSize(rect.size)];
    }
    
    /// 坐标类型枚举
    typedef NS_ENUM(NSUInteger, OIMCoordinateType)
    {
        OIMCoordinateTypeBaidu = 0, // Baidu
        OIMCoordinateTypeMapBar, // MapBar
        OIMCoordinateTypeMapABC, // MapABC
        OIMCoordinateTypeSoSoMap, // SoSoMap
        OIMCoordinateTypeAliYun, // AliYun
        OIMCoordinateTypeGoogle, // Google
        OIMCoordinateTypeGPS, // GPS
    };
    
    /**
     *  转换目标经纬度为高德坐标系
     *
     *  @param coordinate 待转换的经纬度
     *  @param type       坐标系类型
     *
     *  @return 高德坐标系经纬度
     */
    extern CLLocationCoordinate2D OIMCoordinateConvert(CLLocationCoordinate2D coordinate, OIMCoordinateType type);
    
    
#ifdef __cplusplus
}
#endif

@interface NSValue (NSValueOIMGeometryExtensions)

+ (NSValue *)valueWithOIMMapPoint:(OIMMapPoint)mapPoint;
+ (NSValue *)valueWithOIMMapSize:(OIMMapSize)mapSize;
+ (NSValue *)valueWithOIMMapRect:(OIMMapRect)mapRect;
+ (NSValue *)valueWithOIMCoordinate:(CLLocationCoordinate2D)coordinate;

- (OIMMapPoint)OIMMapPointValue;
- (OIMMapSize)OIMMapSizeValue;
- (OIMMapRect)OIMMapRectValue;
- (CLLocationCoordinate2D)OIMCoordinateValue;

@end
