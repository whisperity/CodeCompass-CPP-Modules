require([
  'dojo/topic',
  'dijit/Menu',
  'dijit/MenuItem',
  'dijit/PopupMenuItem',
  'codecompass/astHelper',
  'codecompass/model',
  'codecompass/urlHandler',
  'codecompass/viewHandler'],
function (topic, Menu, MenuItem, PopupMenuItem, astHelper, model, urlHandler, viewHandler) {

  model.addService('cppservice', 'CppService', LanguageServiceClient);

  var getdefintion = {
    id : 'cpp-text-getdefintion',
    render : function (nodeInfo, fileInfo) {
      return new MenuItem({
        label : 'Jump to definition',
        accelKey : 'ctrl - click',
        onClick : function () {
          if (!nodeInfo || !fileInfo)
            return;

          var languageService = model.getLanguageService(fileInfo.type);
          astHelper.jumpToDef(nodeInfo.id, model.cppservice);

          if (window.gtag) {
            window.gtag ('event', 'jump_to_def', {
              'event_category' : urlHandler.getState('wsid'),
              'event_label' : urlHandler.getFileInfo().name
                  + ': '
                  + nodeInfo.astNodeValue
            });
          }
        }
      });
    }
  };

  viewHandler.registerModule(getdefintion, {
    type : viewHandler.moduleType.TextContextMenu,
    service : model.cppservice
  });

  var infoTree = {
    id : 'cpp-text-infotree',
    render : function (nodeInfo, fileInfo) {
      return new MenuItem({
        label : 'Info Tree',
        onClick : function () {
          if (!nodeInfo || !fileInfo)
            return;

          topic.publish('codecompass/infotree', {
            fileType : fileInfo.type,
            elementInfo : nodeInfo
          });

          if (window.gtag) {
              window.gtag ('event', 'info_tree', {
              'event_category' : urlHandler.getState('wsid'),
              'event_label' : urlHandler.getFileInfo().name
                  + ': '
                  + nodeInfo.astNodeValue
            });
          }
        }
      });
    }
  };

  viewHandler.registerModule(infoTree, {
    type : viewHandler.moduleType.TextContextMenu,
    service : model.cppservice
  });

  var infobox = {
    id : 'cpp-text-infobox',
    render : function (nodeInfo, fileInfo) {
      return new MenuItem({
        label : 'Documentation',
        onClick : function () {
          topic.publish('codecompass/documentation', {
            fileType    : fileInfo.type,
            elementInfo : nodeInfo
          });

          if (window.gtag) {
              window.gtag ('event', 'documentation', {
              'event_category' : urlHandler.getState('wsid'),
              'event_label' : urlHandler.getFileInfo().name
                            + ': '
                            + nodeInfo.astNodeValue
            });
          }
        }
      });
    }
  };

  viewHandler.registerModule(infobox, {
    type : viewHandler.moduleType.TextContextMenu,
    service : model.cppservice
  });

  var diagrams = {
    id : 'cpp-text-diagrams',
    render : function (nodeInfo, fileInfo) {
      if (!nodeInfo || !fileInfo)
        return;

      var submenu = new Menu();

      var diagramTypes = model.cppservice.getDiagramTypes(nodeInfo.id);
      for (diagramType in diagramTypes)
        submenu.addChild(new MenuItem({
          label   : diagramType,
          type    : diagramType,
          onClick : function () {
            var that = this;

            topic.publish('codecompass/openDiagram', {
              handler : 'cpp-ast-diagram',
              diagramType : diagramTypes[that.type],
              node : nodeInfo.id
            });
          }
        }));

      submenu.addChild(new MenuItem({
        label : "CodeBites",
        onClick : function () {
          topic.publish('codecompass/codebites', {
            node : nodeInfo
          });
        }
      }));

      if (Object.keys(diagramTypes).length !== 0)
        return new PopupMenuItem({
          label : 'Diagrams',
          popup : submenu
        });
    }
  };

  viewHandler.registerModule(diagrams, {
    type : viewHandler.moduleType.TextContextMenu,
    service : model.cppservice
  });
});
