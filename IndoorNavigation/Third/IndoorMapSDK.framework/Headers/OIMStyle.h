//
//  OIMStyle.h
//  IndoorMapSDK
//
//  Created by Macro on 16/3/1.
//  Copyright © 2016年 Macro. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*!
 *  @brief  字体样式
 *
 *  @remark 暂时只支持一种即默认字体
 *
 *  @since 2.1.0
 */
typedef enum : NSUInteger
{
    /*!
     *  @brief  默认字体
     *
     *  @since 2.1.0
     */
    OIMFontType_Default,

}   OIMFontType;


/*!
 *  @brief  图标文字的标注类型
 *
 *  @since 2.1.0
 */
typedef enum : NSUInteger
{
    /*!
     *  @brief  文字在图标下面，这是默认标注方式
     *
     *  @since 2.1.0
     */
    OIMMarkType_TextUnderIcon,

    /*!
     *  @brief  文字在图标后面
     *
     *  @since 2.1.0
     */
    OIMMarkType_TextAfterIcon,

    /*!
     *  @brief  文字在图标前面
     *
     *  @since 2.1.0
     */
    OIMMarkType_TextBeforeIcon,

    /*!
     *  @brief  文字在图标上面
     *
     *  @since 2.1.0
     */
    OIMMarkType_TextOnIcon,

    /*!
     *  @brief  默认是文字在图标下面
     *
     *  @since 2.1.0
     */
    OIMMarkType_Default = OIMMarkType_TextUnderIcon,

}   OIMMarkType;




/*!
 *  @brief  室内地图POI显示样式
 *
 *  @since 2.1.0
 */
@interface OIMStyle : NSObject

/*!
 *  @brief  初始化一个图标样式
 *
 *  @param imageFile 图标文件路径
 *
 *  @return 样式对象
 *
 *  @since 2.1.0
 */
-(instancetype)initWithImageFile:(NSString*)imageFile;

/*!
 *  @brief  初始化一个点对象样式
 *
 *  @param fontSize      字体大小（为0时不显示文字）
 *  @param fontColor     字体颜色
 *  @param fontType      字体类型
 *  @param fontRotate    文字是否随地图旋转
 *  @param markType      图标文字的标注类型
 *  @param avoidPriority 图标文字避让的优先级，默认是50
 *  @param imageFile     图标文件的相对路径（为空时不显示图标）
 *
 *  @return 样式对象
 *
 *  @since 2.1.0
 */
-(instancetype)initWithFontSize:(float)fontSize fontColor:(UIColor*)fontColor fontType:(OIMFontType)fontType fontRotate:(BOOL)fontRotate markType:(OIMMarkType)markType avoidPriority:(int)avoidPriority imageFile:(NSString*)imageFile;

/*!
 *  @brief  初始化一个面对象样式
 *
 *  @param height         面的拔高，单位：米
 *  @param lineColor      边线的颜色
 *  @param topColor       顶面的颜色
 *  @param sideColor      阳侧面的颜色
 *  @param sideColor2     阴侧面的颜色（暂时未用）
 *  @param highlightColor 高亮显示的颜色
 *
 *  @return 样式对象
 *
 *  @since 2.1.0
 */
-(instancetype)initWithHeight:(float)height lineColor:(UIColor*)lineColor topColor:(UIColor*)topColor sideColor:(UIColor*)sideColor sideColor2:(UIColor*)sideColor2 highlightColor:(UIColor*)highlightColor;

/*!
 *  @brief  初始化一个线对象样式
 *
 *  @param lineSize       线的宽度
 *  @param lineColor      线边的颜色
 *  @param fillColor      线面的颜色
 *  @param highlightColor 线面的高亮颜色
 *
 *  @return 样式对象
 *
 *  @since 2.1.0
 */
-(instancetype)initWithLineSize:(float)lineSize lineColor:(UIColor*)lineColor fillColor:(UIColor*)fillColor highlightColor:(UIColor*)highlightColor;

/*!
 *  @brief  初始化一个样式对象
 *
 *  @param height         拔高的高度，单位：米
 *  @param lineColor      边线的颜色
 *  @param topColor       顶面的颜色
 *  @param sideColor      侧面的颜色
 *  @param sideColor2     侧面的颜色
 *  @param highlightColor 高亮显示的颜色
 *  @param lineSize       线的宽度
 *  @param fontSize       字体的大小（为0时不显示文字）
 *  @param fontColor      字体的颜色
 *  @param fontType       字体的类型
 *  @param fontRotate     文字是否随地图旋转
 *  @param markType       图标文字的标注方式
 *  @param avoidPriority  图标文字的避让优先级
 *  @param imageFile      图标文件的相对路径（为空时不显示图标）
 *
 *  @return 样式对象
 *
 *  @since 2.1.0
 */
-(instancetype)initWithHeight:(float)height lineColor:(UIColor*)lineColor topColor:(UIColor*)topColor sideColor:(UIColor*)sideColor sideColor2:(UIColor*)sideColor2 highlightColor:(UIColor*)highlightColor lineSize:(float)lineSize fontSize:(float)fontSize fontColor:(UIColor*)fontColor fontType:(OIMFontType)fontType fontRotate:(BOOL)fontRotate markType:(OIMMarkType)markType avoidPriority:(int)avoidPriority imageFile:(NSString*)imageFile;


/*!
 *  @brief  拔高的高度，单位：米
 *
 *  @since 2.1.0
 */
@property(nonatomic)float height;

/*!
 *  @brief  边线的颜色
 *
 *  @since 2.1.0
 */
@property(nonatomic, strong)UIColor* lineColor;

/*!
 *  @brief  顶面的颜色
 *
 *  @since 2.1.0
 */
@property(nonatomic, strong)UIColor* topColor;

/*!
 *  @brief  阳侧面的颜色
 *
 *  @since 2.1.0
 */
@property(nonatomic, strong)UIColor* sideColor;

/*!
 *  @brief  阴侧面的颜色（暂时未用）
 *
 *  @since 2.1.0
 */
@property(nonatomic, strong)UIColor* sideColor2;

/*!
 *  @brief  高亮显示的颜色
 *
 *  @since 2.1.0
 */
@property(nonatomic, strong)UIColor* highlightColor;

/*!
 *  @brief  线的宽度
 *
 *  @since 2.1.0
 */
@property(nonatomic)float lineSize;

/*!
 *  @brief  字体的大小（为0时不显示文字）
 *
 *  @since 2.1.0
 */
@property(nonatomic)float fontSize;

/*!
 *  @brief  字体的颜色
 *
 *  @since 2.1.0
 */
@property(nonatomic, strong)UIColor* fontColor;

/*!
 *  @brief  字体的类型
 *
 *  @since 2.1.0
 */
@property(nonatomic)OIMFontType fontType;

/*!
 *  @brief  文字是否随地图旋转
 *
 *  @since 2.1.0
 */
@property(nonatomic)BOOL fontRotate;

/*!
 *  @brief  图标文字的标注类型
 *
 *  @since 2.1.0
 */
@property(nonatomic)OIMMarkType markType;

/*!
 *  @brief  图标文字的避让优先级
 *
 *  @since 2.1.0
 */
@property(nonatomic)int avoidPriority;

/*!
 *  @brief  图标文件的相对路径（为空时不显示图标）
 *
 *  @since 2.1.0
 */
@property(nonatomic, strong)NSString* imageFile;

/*!
 *  @brief  样式生效时的地图缩放级别
 *
 *  @remark 当地图的级别>=样式的级别时，样式生效
 *          也就是说20级的样式，只有当地图放大到20级或以上时才会生效
 *          有多个级别的样式时，小于或等于地图级别的所有样式中，级别最大的样式生效
 *
 *  @since 2.1.0
 */
@property(nonatomic)int level;

@end


