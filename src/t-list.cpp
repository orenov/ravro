// Copyright 2013 Revolution Analytics
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http:// www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "t-list.h"

using namespace Rcpp;
using std::vector;
using std::cerr;
using std::endl;


SEXP t_list(SEXP _ll) {
  List ll(_ll);
  List l_0(as<List>(ll[0]));
  List  tll(l_0.size());
  for(int j = 0; j < tll.size(); j++){
      tll[j] = List(ll.size());
      if (ll.hasAttribute("names")){
        as<List>(tll[j]).names() = ll.names();
      }

  }
  if (l_0.hasAttribute("names")){
      tll.names() = l_0.names();
  }
  for(int i = 0; i < ll.size(); i++) {
    List l_i(as<List>(ll[i]));
    for(int j = 0; j < tll.size(); j++) {
      as<List>(tll[j])[i] = l_i[j];};}
  return wrap(tll);}
