// Copyright 2022-present 650 Industries. All rights reserved.

import React

/**
 The view that just extends `RCTView`. In the future we may add more features here.
 */
open class ExpoView: RCTView {
  public private(set) weak var appContext: AppContext?

  required public init(appContext: AppContext? = nil) {
    self.appContext = appContext
    super.init(frame: .zero)
  }

  required public init?(coder: NSCoder) {
    fatalError("init(coder:) has not been implemented")
  }
}
