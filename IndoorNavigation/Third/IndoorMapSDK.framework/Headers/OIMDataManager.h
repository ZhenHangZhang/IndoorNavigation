//
//  OIMDataManager.h
//  IndoorMapSDK
//
//  Created by Macro on 15/11/26.
//  Copyright © 2015年 Macro. All rights reserved.
//

/*!
 *  @header OIMDataManager.h
 *
 *  @brief 室内数据管理相关接口
 *
 *  @remark 数据管理模块接口包括：
 *      数据下载接口、数据清除接口、
 *      加载数据接口、获取数据接口、
 *      搜索接口
 *
 *  @author Created by Macro on 2016/04/11.
 *
 *  @since 2.0.0
 */


#import <Foundation/Foundation.h>
//#import "OIMType.h"
#import "OIMFeature.h"

@protocol OIMDownloadDelegate;

/*!
 *  @brief  室内数据管理类
 *
 *  @remark 室内数据管理类是按多实例的形式使用，但其底层是一个单实例
 *      因此多个实例之间可能会相互影响，使用时需要注意
 *
 *  @example  //创建类的实例
 *      @property(nonatomic, strong)OIMDataManager* dataManager;
 *      self.imDataManager = [[OIMDataManager alloc]init];
 *
 *  @since 2.0.0
 */
@interface OIMDataManager : NSObject

/*!
 *  @brief  LBS开发者KEY
 *
 *  @remark KEY的获取请到 http://lbs.amap.com 申请
 *      如果KEY设置错误，将无法访问LBS服务器下载室内地图数据
 *      请从LBS官网申请KEY，并在程序中使用正确的KEY
 *      <a href="http://lbs.amap.com/dev/key/"> http://lbs.amap.com/dev/key/</a>
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)NSString* key;

/*!
 *  @brief  数据存储路径
 *
 *  @remark 设置存储路径会影响室内地图数据的缓存
 *      错误的路径（如无权限访问）将缓存失败，导致在每次加载的时候都会重新下载数据
 *      请不要修改该路径下任何内容（包括增加文件），否则会导致无法预知的错误
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)NSString* dataPath;

/*!
 *  @brief  资源文件存储路径
 *
 *  @remark 按类型搜索会从这个路径下读取searchType.csv文件
 *
 *  @since 2.1.0
 */
@property(nonatomic, strong)NSString* resourcePath;

/*!
 *  @brief  数据下载事件回调
 *
 *  @remark 事件的回调是在主线程中（dispatch_get_main_queue()）
 *
 *  @since 2.0.0
 */
@property(nonatomic, weak)id<OIMDownloadDelegate> downloadDelegate;

/*!
 *  @brief  下载指定建筑物的室内地图数据
 *
 *  @param buildingId 室内建筑物Id
 *
 *  @return IMOK  下载启动成功
 *          IMERR 下载启动失败
 *
 *  @remark 请在线申请建筑物数据，建筑物数据申请详情请参阅：http://lbs.amap.com/console/apply/
 *      buildingId必须是高德室内地图的建筑物Id，否则无法成功下载数据
 *      下载室内地图数据可以使用与地图显示不同的buildingId，不影响地图显示
 *      但不要与 OIMMapView 使用同一个数据管理对象，因为 OIMMapView 会处理下载成功或失败的消息，可能会导致不可预知的错误
 *      多次重复下载已经成功下载过的数据，只会提示一次成功事件
 *
 *  @example //下载室内地图数据
 *      NSString* buildingId = @"请输入建筑物ID";
 *      [self.imDataManager downloadBuilding:buildingId];
 *
 *  @since 2.0.0
 */
-(int)downloadBuilding:(NSString*)buildingId;

/*!
 *  @brief  下载指定建筑物的室内地图数据
 *
 *  @param buildingIds 室内建筑物Id列表
 *
 *  @return IMOK  下载启动成功
 *            IMERR 下载启动失败
 *
 *  @remark downloadBuilding接口的简单封装，对buildingIds中的每个Id循环调用downloadBuilding接口
 *
 *  @example //同时下载多栋建筑物的室内地图数据
 *      NSArray buildingIds = [NSArray arrayWithObjects:@"请输入建筑物ID1", @"请输入建筑物ID2", @"请输入建筑物ID3", nil];
 *      [self.imDataManager downloadBuildings:buildingIds];
 *    //等价于
 *      for(NSString* buildingId in buildingIds)
 *          [self.imDataManager downloadBuilding:buildingId];
 *
 *  @since 2.0.0
 */
-(int)downloadBuildings:(NSArray*)buildingIds;

/*!
 *  @brief  删除指定建筑物的室内地图数据
 *
 *  @param buildingId 室内建筑物Id
 *
 *  @return IMOK  删除成功
 *            IMERR 删除失败
 *
 *  @remark 请在线申请建筑物数据，建筑物数据申请详情请参阅：http://lbs.amap.com/console/apply/
 *      该接口只会删除缓存中的数据文件，不影响已经加载到内存中的数据
 *      也就是说删除OIMMapView当前正在显示的建筑物数据，已经显示的地图不会消失
 *
 *  @example //删除室内地图数据
 *      NSString* buildingId = @"请输入建筑物ID";
 *      [self.imDataManager removeBuilding:buildingId];
 *
 *  @since 2.0.0
 */
-(int)removeBuilding:(NSString*)buildingId;

/*!
 *  @brief  删除所有建筑物的室内地图数据
 *
 *  @return IMOK  删除成功
 *            IMERR 删除失败
 *
 *  @remark 该接口会删除数据缓存路径下的所有文件，也就是所有的室内地图数据
 *      请小心使用
 *
 *  @example //删除所有室内地图数据
 *      [self.imDataManager removeAllBuildings];
 *
 *  @since 2.0.0
 */
-(int)removeAllBuildings;

/*!
 *  @brief  获取所有已经缓存的建筑物列表
 *
 *  @return 所有已经缓存的建筑物列表
 *
 *  @remark 获取的是已经缓存的建筑物列表，而不是服务器上可供下载的建筑物列表
 *      SDK不提供可用的建筑物列表
 *      请在线申请建筑物数据，建筑物数据申请详情请参阅：http://lbs.amap.com/console/apply/
 *
 *  @example //获取室内建筑物列表
 *      NSArray* buildingIds = [self.imDataManager getAllBuildings];
 *
 *  @since 2.0.0
 */
-(NSArray*)getAllBuildings;

#pragma mark

/*!
 *  @brief  数据管理模块当前加载的建筑物Id
 *
 *  @remark 请在线申请建筑物数据，建筑物数据申请详情请参阅：http://lbs.amap.com/console/apply/
 *      设置当前建筑物会影响 OIMMapView 的地图显示，不管是否使用同一个数据管理模块的实例
 *      因为对所有的数据管理模块实例，同时只会加载一栋建筑物的一个楼层
 *      设置当前建筑物是异步操作，也就是说设置完成后立即获取，可能不是刚刚设置的新值
 *      设置也有可能失败，失败后当前建筑物Id仍保持设置之前的值，在 OIMMapView 中使用会有相关事件
 *
 *  @example  //当前建筑物
 *      NSString* buildingId = self.imDataManager.buildingId;
 *      buildingId = @"请输入建筑物ID";
 *      self.imDataManager.buildingId = buildingId;
 *      //赋值后立即判断(如[self.imDataManager.buildingId isEqualToString:buildingId])，结果可能为NO
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)NSString* buildingId;

/*!
 *  @brief  数据管理模块当前加载的楼层
 *
 *  @remark 设置当前楼层同样会影响 OIMMapView 的地图显示
 *      因为对所有的数据管理模块实例，同时只会加载一栋建筑物的一个楼层
 *      同样，设置当前楼层是异步操作，也有可能失败，在 OIMMapView 中使用会有相关事件
 *      设置floorNo为0，会加载当前建筑物的默认楼层，设置成功后floorNo不等于0
 *
 *  @example  //当前楼层
 *      int floorNo = self.imDataManager.floorNo;
 *      floorNo = 2;
 *      self.imDataManager.floorNo = floorNo;
 *
 *  @since 2.0.0
 */
@property(nonatomic)int floorNo;

/*!
 *  @brief  获取当前建筑物的所有楼层列表
 *
 *  @return 当前建筑物的所有楼层列表
 *
 *  @remark 返回的是 OIMFloor 对象数组
 *
 *  @example  //获取楼层列表
 *      NSArray* floorList = [self.imDataManager getFloorList];
 *      for(OIMFloor* floor in floorList)
 *      {
 *          int floorNo = floor.floorNo;
 *      }
 *
 *  @since 2.0.0
 */
-(NSArray*)getFloorList;

/*!
 *  @brief  获取当前建筑物的信息
 *
 *  @return 当前建筑物的信息
 *
 *  @example  //获取建筑物信息
 *      OIMBuilding* building = [self.imDataManager getBuildingInfo];
 *      NSString* buildingId = building.pid;
 *
 *  @since 2.0.0
 */
-(OIMBuilding*)getBuildingInfo;



#pragma mark


/*!
 *  @brief  在当前建筑物内按关键字搜索POI
 *
 *  @param keywords 要搜索的关键字
 *  @param floorNo  限定搜索的楼层
 *
 *  @return 搜索出的POI列表
 *
 *  @remark  返回的是 OIMFeature 对象列表
 *
 *  @example  //按关键字搜索
 *      NSArray* features = [self.imDataManager searchByKeywords:@"请输入搜索关键字"];
 *      for(OIMFeature* feature in features)
 *      {
 *          NSString* name = feature.name;
 *      }
 *      [self.imMapView setFeatures:features status:OIMFeatureStatus_Checked];
 *
 *  @since 2.0.0
 */
-(NSArray*)searchByKeywords:(NSString*)keywords;
-(NSArray*)searchByKeywords:(NSString*)keywords floorNo:(int)floorNo;

/*!
 *  @brief  在当前建筑物内按类型搜索POI
 *
 *  @param type 要搜索的类型
 *  @param floorNo  限定搜索的楼层
 *
 *  @return 搜索出的POI列表
 *
 *  @remark  返回的是 OIMFeature 对象列表
 *      搜索的类型值可以从 getAllSearchTypes 返回的类型列表中取得
 *
 *  @example  //按类型搜索
 *      NSArray* features = [self.imDataManager searchByType:@"请输入搜索类型"];
 *      for(OIMFeature* feature in features)
 *      {
 *          NSString* name = feature.name;
 *      }
 *      [self.imMapView setFeatures:features status:OIMFeatureStatus_Checked];
 *
 *  @since 2.0.0
 */
-(NSArray*)searchByType:(NSString*)type;
-(NSArray*)searchByType:(NSString*)type floorNo:(int)floorNo;

/*!
 *  @brief  获取所有可以搜索的类型列表（不同的建筑物可能不同）
 *
 *  @return 所有可以搜索的类型列表
 *
 *  @remark 返回的是NSString*类型的数组
 *
 *  @example  //获取可以搜索的类型
 *      NSArray* types = [self.imDataManager getAllSearchTypes];
 *      for(NSString* type in types)
 *      {
 *          [self.imDataManager searchByType:type];
 *      }
 *
 *  @since 2.0.0
 */
-(NSArray*)getAllSearchTypes;

/*!
 *  @brief  在当前建筑物内按高德分类列表搜索POI
 *
 *  @param categories 要搜索的高德分类列表
 *  @param floorNo  限定搜索的楼层
 *
 *  @return 搜索出的POI列表
 *
 *  @remark  返回的是 OIMFeature 对象列表
 *
 *  @example  //按类型搜索
 *      NSArray* categories = [NSArray arrayWithObjects:@(50800), @(981151), nil];
 *      NSArray* features = [self.imDataManager searchByCategories:categories];
 *      for(OIMFeature* feature in features)
 *      {
 *          NSString* name = feature.name;
 *      }
 *      [self.imMapView setFeatures:features status:OIMFeatureStatus_Checked];
 *
 *  @since 2.0.0
 */
-(NSArray*)searchByCategories:(NSArray*)categories;
-(NSArray*)searchByCategories:(NSArray*)categories floorNo:(int)floorNo;

/*!
 *  @brief  在指定位置所有在楼层按距离搜索POI
 *
 *  @param position 指定的位置，包括经纬度和楼层
 *  @param distance 离指定位置的距离（单位：米）
 *  @param limit    POI个数限制
 *
 *  @return 搜索出的POI列表
 *
 *  @remark  返回的是 OIMFeature 对象列表
 *      距离是按指定点到POI中心点的直线距离计算，并且只返回当前楼层的POI
 *
 *  @example  //获取10米内最近的一个POI
 *      OIMPoint position = {120.2345, 39.6789, 1};
 *      NSArray* features = [self.imDataManager search:position byDistance:10 limit:1];
 *      for(OIMFeature* feature in features)
 *      {
 *          NSString* name = feature.name;
 *      }
 *      [self.imMapView setFeatures:features status:OIMFeatureStatus_Checked];
 *
 *  @since 2.0.0
 */
-(NSArray*)search:(OIMPoint)position byDistance:(float)distance limit:(int)limit;


/*!
 *  @brief  根据id获取相关POI信息
 *
 *  @param featureId POI的唯一标识
 *
 *  @return POI相关信息
 *
 *  @remark featureId必须是高德室内地图中的有效id
 *      只有加载了feature对应的建筑物楼层之后，才能获取到相关的POI信息
 *
 *  @example    //根据ID获取Feature对象
 *      OIMFeature* feature = [self.imDataManager getFeatureById:@"UseCorrectId"];
 *
 *  @since 2.0.0
 */
-(OIMFeature *)getFeatureById:(NSString *)featureId;


/*!
 *  @brief  加载外延数据
 *
 *  @param extensionData 外延数据
 *
 *  @return IMOK    成功
 *          IMERR   失败
 *
 *  @since 2.1.0
 */
-(int)loadExtensionData:(NSData*)extensionData;



@end

#pragma mark

/*!
 *  @brief  数据下载事件
 *
 *  @since 2.0.0
 */
@protocol OIMDownloadDelegate <NSObject>

/*!
 *  @brief  数据下载或更新成功
 *
 *  @param dataManager 数据管理对象
 *  @param buildingId  室内建筑物Id
 *  @param updated     是否有新数据下载下来
 *
 *  @since 2.0.0
 */
-(void)dataManager:(OIMDataManager*)dataManager didDownloadSuccess:(NSString*)buildingId updated:(BOOL)updated;

/*!
 *  @brief  数据下载或更新失败
 *
 *  @param dataManager 数据管理对象
 *  @param buildingId  室内建筑物Id
 *  @param error       失败相关的错误信息
 *
 *  @since 2.0.0
 */
-(void)dataManager:(OIMDataManager*)dataManager didDownloadFailure:(NSString*)buildingId error:(NSError*)error;

@optional
/*!
 *  @brief  数据下载过程（可选）
 *
 *  @param dataManager 数据管理对象
 *  @param buildingId  室内建筑物Id
 *  @param percent     已下载数据的百分比
 *
 *  @remark 该事件是以大概每秒一次的频率触发，0%和100%时不保证触发事件
 *      整个下载过程中，该事件也可能一次也不会触发
 *
 *  @since 2.0.0
 */
-(void)dataManager:(OIMDataManager*)dataManager didDownload:(NSString*)buildingId percent:(int)percent;

@end





