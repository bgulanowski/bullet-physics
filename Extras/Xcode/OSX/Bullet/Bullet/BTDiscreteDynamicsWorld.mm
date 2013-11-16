//
//  BTDiscreteDynamicsWorld.m
//  Bullet
//
//  Created by Brent Gulanowski on 2013-06-20.
//  Copyright (c) 2013 Lichen Labs. All rights reserved.
//

#import "BTDiscreteDynamicsWorld.h"

#import "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"
#import "BulletCollision/BroadphaseCollision/btDispatcher.h"
#import "BulletCollision/BroadphaseCollision/btSimpleBroadphase.h"
#import "BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h"
#import "BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h"


@implementation BTDiscreteDynamicsWorld {
    btCollisionConfiguration *_config;
    btDispatcher *_dispatcher;
    btBroadphaseInterface *_interface;
    btConstraintSolver *_solver;
    btDiscreteDynamicsWorld *_world;
}

- (void)dealloc {
    if(_world) delete _world;
    if(_solver) delete _solver;
    if(_interface) delete _interface;
    if(_dispatcher) delete _dispatcher;
    if(_config) delete _config;
}

- (id)init {
    self = [super init];
    if(self) {
        _config = new btDefaultCollisionConfiguration();
        _dispatcher = new btCollisionDispatcher(_config);
        _interface = new btSimpleBroadphase();
        _solver = new btSequentialImpulseConstraintSolver();
        _world = new btDiscreteDynamicsWorld(_dispatcher, _interface, _solver, _config);
    }
    return self;
}

@end
