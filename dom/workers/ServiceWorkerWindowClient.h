/* -*- Mode: IDL; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef mozilla_dom_workers_serviceworkerwindowclient_h
#define mozilla_dom_workers_serviceworkerwindowclient_h

#include "ServiceWorkerClient.h"

namespace mozilla {
namespace dom {
namespace workers {

class ServiceWorkerWindowClient MOZ_FINAL : public ServiceWorkerClient
{
public:
  ServiceWorkerWindowClient(nsISupports* aOwner,
                            const ServiceWorkerClientInfo& aClientInfo)
    : ServiceWorkerClient(aOwner, aClientInfo),
      mVisibilityState(aClientInfo.mVisibilityState),
      mFocused(aClientInfo.mFocused),
      mFrameType(aClientInfo.mFrameType)
  {
  }

  virtual JSObject*
  WrapObject(JSContext* aCx) MOZ_OVERRIDE;

  mozilla::dom::VisibilityState
  VisibilityState() const
  {
    return mVisibilityState;
  }

  bool
  Focused() const
  {
    return mFocused;
  }

  mozilla::dom::FrameType
  FrameType() const
  {
    return mFrameType;
  }

  already_AddRefed<Promise>
  Focus() const;

private:
  ~ServiceWorkerWindowClient()
  { }

  mozilla::dom::VisibilityState mVisibilityState;
  bool mFocused;
  mozilla::dom::FrameType mFrameType;
};

} // namespace workers
} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_workers_serviceworkerwindowclient_h
